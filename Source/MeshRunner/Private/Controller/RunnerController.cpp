// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/RunnerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Character/Runner.h"
#include "GameMode/MeshRunnerGameMode.h"

void ARunnerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}

	RunnerPlayer = MakeWeakObjectPtr(Cast<ARunner>(GetCharacter()));
	GameMode = MakeWeakObjectPtr(Cast<AMeshRunnerGameMode>(GetWorld()->GetAuthGameMode()));
}

void ARunnerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInput->BindAction(LeftAction, ETriggerEvent::Started, this, &ARunnerController::InputLeftKey);
		EnhancedInput->BindAction(RightAction, ETriggerEvent::Started, this, &ARunnerController::InputRightKey);
	}
}

void ARunnerController::InputLeftKey()
{
	if (GameMode.IsValid() && !GameMode->IsRaceStarted())
	{
		GameMode->SetRaceStarted(true);
	}
	
	if (LastInput == ERunnerInputType::Right)
	{
		RunnerPlayer->IncreaseSpeed();
		LastInput = ERunnerInputType::Left;
	}
}

void ARunnerController::InputRightKey()
{
	if (GameMode.IsValid() && !GameMode->IsRaceStarted())
	{
		GameMode->SetRaceStarted(true);
	}
	
	if (LastInput == ERunnerInputType::Left)
	{
		RunnerPlayer->IncreaseSpeed();
		LastInput = ERunnerInputType::Right;
	}
}
