// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/RunnerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void ARunnerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
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
	UE_LOG(LogTemp, Warning, TEXT("Input Left Key."));
}

void ARunnerController::InputRightKey()
{
	UE_LOG(LogTemp, Warning, TEXT("Input Right Key."));
}
