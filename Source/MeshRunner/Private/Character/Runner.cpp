// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Runner.h"

#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameMode/MeshRunnerGameMode.h"
#include "Kismet/GameplayStatics.h"

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

void ARunner::BeginPlay()
{
	Super::BeginPlay();

	GameMode = MakeWeakObjectPtr(Cast<AMeshRunnerGameMode>(GetWorld()->GetAuthGameMode()));
}

void ARunner::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Add Speed Per Tick (Front Direction is Forward X)
	AddMovementInput(FVector(1, 0, 0));
	
	// Speed Decrease Per Tick
	float SpeedDecrease = SpeedDecreaseRampCurve->GetFloatValue(GetVelocity().Length()) * SpeedDecreasePerTickWithDelta * DeltaSeconds;
	if (GameMode.IsValid() && GameMode->IsRaceOver())
	{
		SpeedDecrease *= SlowMultiplierWhenRaceOver;
	}
	
	GetCharacterMovement()->MaxWalkSpeed = FMath::Max(0, GetCharacterMovement()->MaxWalkSpeed - SpeedDecrease);

	// Update Sprite
	GetSprite()->SetFlipbook(GetVelocity().Length() > 0 ? RunFlipbook : IdleFlipbook);
	GetSprite()->SetPlayRate(GetSprite()->GetFlipbook() == RunFlipbook ? GetVelocity().Length() / MaxSpeed : 1.0f);

	if (GetSprite()->GetFlipbook() == RunFlipbook)
	{
		const int32 Frame = GetSprite()->GetPlaybackPositionInFrames();
		if (Frame != LastFrame && (Frame == 1 || Frame == 5))
		{
			LastFrame = Frame;
			UGameplayStatics::PlaySound2D(this, FootstepSoundCue);
		}
	}
}

void ARunner::IncreaseSpeed() const
{
	if (GameMode.IsValid() && GameMode->IsRaceStarted() && !GameMode->IsRaceOver())
	{
		const float SpeedIncrease = SpeedIncreaseRampCurve->GetFloatValue(GetVelocity().Length()) * SpeedIncreasePerTab;
		GetCharacterMovement()->MaxWalkSpeed = FMath::Min(MaxSpeed, GetCharacterMovement()->MaxWalkSpeed + SpeedIncrease);
	}
}

void ARunner::AnnounceWinner(const int32 WinnerIndex) const
{
	if (GameMode.IsValid() && !GameMode->IsRaceOver())
	{
		UE_LOG(LogTemp, Warning, TEXT("Winner is %d"), WinnerIndex);
	}
}

