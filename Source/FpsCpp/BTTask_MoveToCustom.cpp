// Fill out your copyright notice in the Description page of Project Settings.

#include "FpsCpp.h"
#include "BTTask_MoveToCustom.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "NpcAIController.h"
#include "FpsCppCharacter.h"


EBTNodeResult::Type UBTTask_MoveToCustom::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) {
    ANpcAIController* npcController = Cast<ANpcAIController>(OwnerComp.GetAIOwner());
    AFpsCppCharacter* playerCharacter = Cast<AFpsCppCharacter>(
            OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(npcController->enemyKeyId));
    if (playerCharacter) {
        npcController->MoveToActor(playerCharacter, 5.0f);
        return EBTNodeResult::Succeeded;
    } else {
        return EBTNodeResult::Failed;
    }
}
