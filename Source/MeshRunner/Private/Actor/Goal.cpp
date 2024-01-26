// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Goal.h"

#include "PaperSpriteComponent.h"
#include "Character/Runner.h"
#include "Components/BoxComponent.h"
#include "GameMode/MeshRunnerGameMode.h"

AGoal::AGoal()
{
	PrimaryActorTick.bCanEverTick = false;

	PaperSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSpriteComponent"));
	PaperSpriteComponent->SetupAttachment(RootComponent);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(PaperSpriteComponent);
}

void AGoal::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (GoalConnectedStripe)
	{
		PaperSpriteComponent->SetSprite(GoalConnectedStripe);
	}
}

void AGoal::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AGoal::OnBeginOverlap);
}


void AGoal::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor, UPrimitiveComponent* OtherComp,
                           int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult)
{
	if (const ARunner* Runner = Cast<ARunner>(OtherActor))
	{
		Runner->AnnounceWinner(LaneIndex);
		
		if (GoalRippedStripe)
		{
			PaperSpriteComponent->SetSprite(GoalRippedStripe);
		}

		if (AMeshRunnerGameMode* GameMode = Cast<AMeshRunnerGameMode>(GetWorld()->GetAuthGameMode()))
		{
			GameMode->SetRaceOver(true);
			GameMode->RestartRace();
		}
	}
}


