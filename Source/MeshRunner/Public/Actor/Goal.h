// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Goal.generated.h"

class UBoxComponent;
class UPaperSprite;
class UPaperSpriteComponent;

UCLASS()
class MESHRUNNER_API AGoal : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere)
	UPaperSpriteComponent* PaperSpriteComponent;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Goal")
	UPaperSprite* GoalConnectedStripe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Goal")
	UPaperSprite* GoalRippedStripe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Goal")
	int32 LaneIndex;

private:
	FComponentBeginOverlapSignature OnGoalCollisionOverlapDelegate;

public:
	AGoal();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	
private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
