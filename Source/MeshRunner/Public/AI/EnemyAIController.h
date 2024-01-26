// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

class ARunner;

UCLASS()
class MESHRUNNER_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunnerAI")
	float InputDelayMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunnerAI")
	float InputDelayMax;
	
protected:
	TWeakObjectPtr<ARunner> Runner;

protected:
	FTimerHandle InputTimer;
	
protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaSeconds) override;

	
};
