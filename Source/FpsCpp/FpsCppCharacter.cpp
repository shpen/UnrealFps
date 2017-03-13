// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FpsCpp.h"
#include "FpsCppCharacter.h"
#include "FpsCppProjectile.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "MotionControllerComponent.h"
#include "DrawDebugHelpers.h"
#include "MyPlayerController.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AFpsCppCharacter

AFpsCppCharacter::AFpsCppCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	Mesh1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P, FP_Gun, and VR_Gun 
	// are set in the derived blueprint asset named MyCharacter to avoid direct content references in C++.

	// Create VR Controllers.
	R_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("R_MotionController"));
	R_MotionController->Hand = EControllerHand::Right;
	R_MotionController->SetupAttachment(RootComponent);
	L_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("L_MotionController"));
	L_MotionController->SetupAttachment(RootComponent);

	// Create a gun and attach it to the right-hand VR controller.
	// Create a gun mesh component
	VR_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VR_Gun"));
	VR_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	VR_Gun->bCastDynamicShadow = false;
	VR_Gun->CastShadow = false;
	VR_Gun->SetupAttachment(R_MotionController);
	VR_Gun->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	VR_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("VR_MuzzleLocation"));
	VR_MuzzleLocation->SetupAttachment(VR_Gun);
	VR_MuzzleLocation->SetRelativeLocation(FVector(0.000004, 53.999992, 10.000000));
	VR_MuzzleLocation->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));		// Counteract the rotation of the VR gun model.

	flashLightNarrow = CreateDefaultSubobject<USpotLightComponent>(TEXT("FlashlightNarrow"));
	flashLightNarrow->SetupAttachment(FirstPersonCameraComponent);
	flashLightNarrow->SetVisibility(false);

	flashLightWide = CreateDefaultSubobject<USpotLightComponent>(TEXT("FlashlightWide"));
	flashLightWide->SetupAttachment(FirstPersonCameraComponent);
	flashLightWide->SetVisibility(false);

	// Uncomment the following line to turn motion controllers on by default:
	//bUsingMotionControllers = true;

	// Ray casting defaults
	DrawRay = false;
	RayLength = 200.0f;
	FireRate = 10.0f;
}

void AFpsCppCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	// Show or hide the two versions of the gun based on whether or not we're using motion controllers.
	if (bUsingMotionControllers)
	{
		VR_Gun->SetHiddenInGame(false, true);
		Mesh1P->SetHiddenInGame(true, true);
	}
	else
	{
		VR_Gun->SetHiddenInGame(true, true);
		Mesh1P->SetHiddenInGame(false, true);
	}

	//Initializing our reference
	LastItemSeen = nullptr;

	//Initializing our Inventory
	Inventory.SetNum(MAX_INVENTORY_ITEMS);
}

void AFpsCppCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Raycast();
}

void AFpsCppCharacter::Raycast()
{
	//Calculating start and end location
	FVector StartLocation = FirstPersonCameraComponent->GetComponentLocation();
	FVector EndLocation = StartLocation + (FirstPersonCameraComponent->GetForwardVector() * RayLength);

	FHitResult RaycastHit;

	//Raycast should ignore the character
	FCollisionQueryParams CQP;
	CQP.AddIgnoredActor(this);

	//Raycast
	GetWorld()->LineTraceSingleByChannel(RaycastHit, StartLocation, EndLocation, ECollisionChannel::ECC_WorldDynamic, CQP);

	APickupActor* Pickup = Cast<APickupActor>(RaycastHit.GetActor());

	// Check if we are looking at something new
	if (LastItemSeen != Pickup)
	{
		if (LastItemSeen)
		{
			// Disable the glowing effect on the previous seen item if it exists
			LastItemSeen->SetGlowEffect(false);
		}
		
		if (Pickup)
		{
			//Enable the glow effect on the current item if it exists
			LastItemSeen = Pickup;
			Pickup->SetGlowEffect(true);
		}
		else
		{
			// Re-Initialize if we are looking at nothing
			LastItemSeen = nullptr;
		}
	}
}

void AFpsCppCharacter::PickupItem()
{
	if (LastItemSeen)
	{
		//Find the first available slot
		int32 AvailableSlot = Inventory.Find(nullptr);

		if (AvailableSlot != INDEX_NONE)
		{
			//Add the item to the first valid slot we found
			Inventory[AvailableSlot] = LastItemSeen->GetClass()->GetDefaultObject<APickupActor>();
			//Destroy the item from the game
			LastItemSeen->Destroy();
		}
		else GLog->Log("You can't carry any more items!");
	}
}

void AFpsCppCharacter::setEquippedItem(APickupActor *item)
{
    if (item)
    {
        CurrentlyEquippedItem = item;
        GLog->Log("I've set a new equipped item: " + CurrentlyEquippedItem->GetName());
    }
    else GLog->Log("The Player has clicked an empty inventory slot");
}

void AFpsCppCharacter::DropEquippedItem()
{
    if (CurrentlyEquippedItem)
    {
        int32 IndexOfItem;
        if (Inventory.Find(CurrentlyEquippedItem, IndexOfItem))
        {
            //The location of the drop
            FVector DropLocation = GetActorLocation() + (GetActorForwardVector() * 200);

            //Making a transform with default rotation and scale. Just setting up the location
            //that was calculated above
            FTransform Transform; Transform.SetLocation(DropLocation);

            //Default actor spawn parameters
            FActorSpawnParameters SpawnParams;

            //Spawning our pickup
            APickupActor* PickupToSpawn = GetWorld()->SpawnActor<APickupActor>(CurrentlyEquippedItem->GetClass(), Transform, SpawnParams);


            if (PickupToSpawn)
            {
                //Unreference the item we've just placed
                Inventory[IndexOfItem] = nullptr;
            }
        }
    }
}

void AFpsCppCharacter::HandleInventoryInput()
{
	AMyPlayerController* Con = Cast<AMyPlayerController>(GetController());
	if (Con) Con->HandleInventoryInput();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AFpsCppCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AFpsCppCharacter::TouchStarted);
	if (EnableTouchscreenMovement(PlayerInputComponent) == false)
	{
		PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFpsCppCharacter::OnFire);
		PlayerInputComponent->BindAction("Fire", IE_Released, this, &AFpsCppCharacter::OnFireReleased);
	}

	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AFpsCppCharacter::OnResetVR);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFpsCppCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFpsCppCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AFpsCppCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFpsCppCharacter::LookUpAtRate);

	//Action mapping of item interaction
    PlayerInputComponent->BindAction("Use", IE_Pressed, this, &AFpsCppCharacter::PickupItem);
    PlayerInputComponent->BindAction("Drop", IE_Pressed, this, &AFpsCppCharacter::DropEquippedItem);

    FInputActionBinding InventoryBinding;
    //We need this bind to execute on pause state
    InventoryBinding.bExecuteWhenPaused = true;
    InventoryBinding.ActionDelegate.BindDelegate(this, FName("HandleInventoryInput"));
    InventoryBinding.ActionName = FName("Inventory");
    InventoryBinding.KeyEvent = IE_Pressed;

    //Binding the Inventory action
    PlayerInputComponent->AddActionBinding(InventoryBinding);

	PlayerInputComponent->BindAction("Flashlight", IE_Pressed, this, &AFpsCppCharacter::toggleFlashlight);
}

void AFpsCppCharacter::OnFire()
{
	GetWorldTimerManager().SetTimer(FireTimerHandle, this, &AFpsCppCharacter::Fire, 1.0f / FireRate, true, 0.0f);
}

void AFpsCppCharacter::OnFireReleased()
{
	GetWorldTimerManager().ClearTimer(FireTimerHandle);
}

void AFpsCppCharacter::Fire()
{
	// try and fire a projectile
	if (ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			if (bUsingMotionControllers)
			{
				const FRotator SpawnRotation = VR_MuzzleLocation->GetComponentRotation();
				const FVector SpawnLocation = VR_MuzzleLocation->GetComponentLocation();
				World->SpawnActor<AFpsCppProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
			}
			else
			{
				const FRotator SpawnRotation = GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

				//Set Spawn Collision Handling Override
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				// spawn the projectile at the muzzle
				World->SpawnActor<AFpsCppProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
			}
		}
	}

	// try and play the sound if specified
	if (FireSound != NULL)
	{
	//UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != NULL)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

void AFpsCppCharacter::toggleFlashlight() {
	flashLightNarrow->ToggleVisibility();
	flashLightWide->ToggleVisibility();
}

void AFpsCppCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AFpsCppCharacter::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == true)
	{
		return;
	}
	TouchItem.bIsPressed = true;
	TouchItem.FingerIndex = FingerIndex;
	TouchItem.Location = Location;
	TouchItem.bMoved = false;
}

void AFpsCppCharacter::EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == false)
	{
		return;
	}
	if ((FingerIndex == TouchItem.FingerIndex) && (TouchItem.bMoved == false))
	{
		OnFire();
	}
	TouchItem.bIsPressed = false;
}

//Commenting this section out to be consistent with FPS BP template.
//This allows the user to turn without using the right virtual joystick

//void AFpsCppCharacter::TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location)
//{
//	if ((TouchItem.bIsPressed == true) && (TouchItem.FingerIndex == FingerIndex))
//	{
//		if (TouchItem.bIsPressed)
//		{
//			if (GetWorld() != nullptr)
//			{
//				UGameViewportClient* ViewportClient = GetWorld()->GetGameViewport();
//				if (ViewportClient != nullptr)
//				{
//					FVector MoveDelta = Location - TouchItem.Location;
//					FVector2D ScreenSize;
//					ViewportClient->GetViewportSize(ScreenSize);
//					FVector2D ScaledDelta = FVector2D(MoveDelta.X, MoveDelta.Y) / ScreenSize;
//					if (FMath::Abs(ScaledDelta.X) >= 4.0 / ScreenSize.X)
//					{
//						TouchItem.bMoved = true;
//						float Value = ScaledDelta.X * BaseTurnRate;
//						AddControllerYawInput(Value);
//					}
//					if (FMath::Abs(ScaledDelta.Y) >= 4.0 / ScreenSize.Y)
//					{
//						TouchItem.bMoved = true;
//						float Value = ScaledDelta.Y * BaseTurnRate;
//						AddControllerPitchInput(Value);
//					}
//					TouchItem.Location = Location;
//				}
//				TouchItem.Location = Location;
//			}
//		}
//	}
//}

void AFpsCppCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AFpsCppCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AFpsCppCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AFpsCppCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

bool AFpsCppCharacter::EnableTouchscreenMovement(class UInputComponent* PlayerInputComponent)
{
	bool bResult = false;
	if (FPlatformMisc::GetUseVirtualJoysticks() || GetDefault<UInputSettings>()->bUseMouseForTouch)
	{
		bResult = true;
		PlayerInputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AFpsCppCharacter::BeginTouch);
		PlayerInputComponent->BindTouch(EInputEvent::IE_Released, this, &AFpsCppCharacter::EndTouch);

		//Commenting this out to be more consistent with FPS BP template.
		//PlayerInputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AFpsCppCharacter::TouchUpdate);
	}
	return bResult;
}
