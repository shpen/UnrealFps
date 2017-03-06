// Fill out your copyright notice in the Description page of Project Settings.

#include "FpsCpp.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "NpcAIController.h"
#include "FpsCppCharacter.h"
#include "BTService_CheckForPlayer.h"

UBTService_CheckForPlayer::UBTService_CheckForPlayer() {
    bCreateNodeInstance = true;
}

void UBTService_CheckForPlayer::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) {
    ANpcAIController* npcController = Cast<ANpcAIController>(OwnerComp.GetOwner());
    if (npcController) {
        AFpsCppCharacter* player = Cast<AFpsCppCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
        if (player) {
            OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(npcController->enemyKeyId, player);
        }
    }
}