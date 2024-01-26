// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Runner.h"

#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ARunner::ARunner()
{
	PrimaryActorTick.bCanEverTick = true;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	GetCharacterMovement()->MaxWalkSpeed = 0.0f;
}

void ARunner::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (IdleFlipbook)
	{
		GetSprite()->SetFlipbook(IdleFlipbook);
	}
}

void ARunner::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Add Speed Per Tick (Front Direction is Forward X)
	AddMovementInput(FVector(1, 0, 0));
	
	// Speed Decrease Per Tick
	const float SpeedDecrease = SpeedDecreaseRampCurve->GetFloatValue(GetVelocity().Length()) * SpeedDecreasePerTickWithDelta * DeltaSeconds;
	GetCharacterMovement()->MaxWalkSpeed =FMath::Max(0, GetCharacterMovement()->MaxWalkSpeed - SpeedDecrease);

	// Update Sprite
	GetSprite()->SetFlipbook(GetVelocity().Length() > 0 ? RunFlipbook : IdleFlipbook);
	GetSprite()->SetPlayRate(GetSprite()->GetFlipbook() == RunFlipbook ? GetVelocity().Length() / MaxSpeed : 1.0f);
}

void ARunner::IncreaseSpeed() const
{
	const float SpeedIncrease = SpeedIncreaseRampCurve->GetFloatValue(GetVelocity().Length()) * SpeedIncreasePerTab;
	GetCharacterMovement()->MaxWalkSpeed = FMath::Min(MaxSpeed, GetCharacterMovement()->MaxWalkSpeed + SpeedIncrease);
}

