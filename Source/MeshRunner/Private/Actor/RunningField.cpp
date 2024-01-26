// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/RunningField.h"

#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Components/BoxComponent.h"

ARunningField::ARunningField()
{
	PrimaryActorTick.bCanEverTick = false;

	TopLaneCollisionBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("TopLaneCollisionBoxComponent"));
	TopLaneCollisionBoxComponent->SetupAttachment(RootComponent);
	
	BottomLaneCollisionBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BottomLaneCollisionBoxComponent"));
	BottomLaneCollisionBoxComponent->SetupAttachment(RootComponent);

	TopLaneGoal = CreateDefaultSubobject<UChildActorComponent>(TEXT("TopLaneGoal"));
	TopLaneGoal->SetupAttachment(RootComponent);
	
	BottomLaneGoal = CreateDefaultSubobject<UChildActorComponent>(TEXT("BottomLaneGoal"));
	BottomLaneGoal->SetupAttachment(RootComponent);
}

void ARunningField::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	
	if (RunningFieldSprite)
	{
		// Create Running Field Sprites
		const float SpriteSizeX = RunningFieldSprite->GetSourceSize().X * 4;
		if (RunningFieldSprite)
		{
			for (int i = 0; i < AmountOfRunningFieldToCreate; i++)
			{
				UPaperSpriteComponent* SpriteComponent = NewObject<UPaperSpriteComponent>(this);
				SpriteComponent->RegisterComponent();
				SpriteComponent->SetSprite(RunningFieldSprite);
				SpriteComponent->SetRelativeLocation(FVector(SpriteSizeX * i, 0, 0));
			}
		}

		// Setup Track Collision Boxes
		const float LainSizeX = AmountOfRunningFieldToCreate * SpriteSizeX / 2;
		const FVector CollisionBoxSize = FVector(LainSizeX, 100, 1);
	
		TopLaneCollisionBoxComponent->SetBoxExtent(CollisionBoxSize);
		TopLaneCollisionBoxComponent->SetRelativeLocation(FVector(LainSizeX - SpriteSizeX / 2, CollisionBoxSize.Y / 2, TopLaneOffsetZ));
	
		BottomLaneCollisionBoxComponent->SetBoxExtent(CollisionBoxSize);
		BottomLaneCollisionBoxComponent->SetRelativeLocation(FVector(LainSizeX - SpriteSizeX / 2, CollisionBoxSize.Y / 2, BottomLaneOffsetZ));

		// Setup Goal Collision Boxes
		const float LainGoalX = SpriteSizeX * (AmountOfRunningFieldToCreate - 2);
		TopLaneGoal->SetRelativeLocation(FVector(LainGoalX + TopLaneGoalOffsetXZ.X, 1, TopLaneGoalOffsetXZ.Y));
		BottomLaneGoal->SetRelativeLocation(FVector(LainGoalX + BottomLaneGoalOffsetXZ.X, 1, BottomLaneGoalOffsetXZ.Y));
	}
}
