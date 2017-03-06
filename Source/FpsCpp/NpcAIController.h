// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "NpcAIController.generated.h"

/**
 * 
 */
UCLASS()
class FPSCPP_API ANpcAIController : public AAIController
{
	GENERATED_BODY()

	class UBlackboardComponent* blackboardComp;

	class UBehaviorTreeComponent* behaviorTreeComp;

public:

    ANpcAIController();

    virtual void Possess(APawn *inPawn) override;

    uint8 enemyKeyId;
};
