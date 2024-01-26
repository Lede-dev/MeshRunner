// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EnemyAIController.h"

#include "Character/Runner.h"
#include "GameMode/MeshRunnerGameMode.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	GameMode = Cast<AMeshRunnerGameMode>(GetWorld()->GetAuthGameMode());
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	Runner = Cast<ARunner>(InPawn);
}

void AEnemyAIController::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (GameMode.IsValid() && GameMode->IsRaceStarted())
	{
		if (!GetWorld()->GetTimerManager().IsTimerActive(InputTimer))
		{
			const float RandomInputDelay = FMath::RandRange(InputDelayMin, InputDelayMax);
			GetWorld()->GetTimerManager().SetTimer(InputTimer, [this]
			{
				if (Runner.IsValid())
				{
					Runner->IncreaseSpeed();
				}
			}, RandomInputDelay, false);
		}
	}
}
