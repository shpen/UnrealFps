// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTService.h"
#include "BTService_CheckForPlayer.generated.h"

/**
 * 
 */
UCLASS()
class FPSCPP_API UBTService_CheckForPlayer : public UBTService
{
	GENERATED_BODY()

protected:
    UBTService_CheckForPlayer();

    void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;

 
};
