// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_MoveToCustom.generated.h"

/**
 * 
 */
UCLASS()
class FPSCPP_API UBTTask_MoveToCustom : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;


};
