// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Runner.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ARunner::ARunner()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);
}
