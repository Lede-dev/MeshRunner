// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MeshRunnerGameMode.h"

#include "Kismet/GameplayStatics.h"

void AMeshRunnerGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AMeshRunnerGameMode::RestartRace()
{
	if (!GetWorld()->GetTimerManager().IsTimerActive(RaceRestartTimer))
	{
		GetWorld()->GetTimerManager().SetTimer(RaceRestartTimer, [this]
		{
			const FString LevelName = UGameplayStatics::GetCurrentLevelName(this);
			UGameplayStatics::OpenLevel(this, FName(LevelName));
		}, RaceRestartDelay, false);
	}
}
