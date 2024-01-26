// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EnemyAIController.h"

#include "Character/Runner.h"

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	Runner = Cast<ARunner>(InPawn);
}

void AEnemyAIController::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!GetWorld()->GetTimerManager().IsTimerActive(InputTimer))
	{
		const float RandomInputDelay = FMath::RandRange(InputDelayMin, InputDelayMax);
		GetWorld()->GetTimerManager().SetTimer(InputTimer, [this]
		{
			Runner->IncreaseSpeed();
			GetWorld()->GetTimerManager().ClearTimer(InputTimer);
		}, RandomInputDelay, false);
	}
}
