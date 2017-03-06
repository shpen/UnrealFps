// Fill out your copyright notice in the Description page of Project Settings.

#include "FpsCpp.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "NpcAIController.h"
#include "NpcCharacter.h"


ANpcAIController::ANpcAIController() {
    blackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
    behaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
}

void ANpcAIController::Possess(APawn *inPawn) {
    Super::Possess(inPawn);

    ANpcCharacter* character = Cast<ANpcCharacter>(inPawn);

    if (character && character->botBehavior) {
        blackboardComp->InitializeBlackboard(*character->botBehavior->BlackboardAsset);
        enemyKeyId = blackboardComp->GetKeyID("Player");

        behaviorTreeComp->StartTree(*character->botBehavior);
    }
}