// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MeshRunnerGameMode.generated.h"

UCLASS()
class MESHRUNNER_API AMeshRunnerGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MeshRunner")
	float RaceRestartDelay;

protected:
	bool bIsRaceOver;
	bool bIsRaceStarted;

	FTimerHandle RaceRestartTimer;

protected:
	virtual void BeginPlay() override;

public:
	bool IsRaceOver() const { return bIsRaceOver; }
	void SetRaceOver(const bool InbIsRaceOver) { bIsRaceOver = InbIsRaceOver; }
	
	bool IsRaceStarted() const { return bIsRaceStarted; }
	void SetRaceStarted(const bool InbIsRaceStarted) { bIsRaceStarted = InbIsRaceStarted; }
	
	void RestartRace();
	
};
