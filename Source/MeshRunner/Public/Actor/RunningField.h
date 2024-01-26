// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RunningField.generated.h"

class UBoxComponent;
class UPaperSprite;
class UPaperSpriteComponent;

UCLASS()
class MESHRUNNER_API ARunningField : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* TopLaneCollisionBoxComponent;
	
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BottomLaneCollisionBoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="RunningField")
	UChildActorComponent* TopLaneGoal;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="RunningField")
	UChildActorComponent* BottomLaneGoal;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunningField")
	UPaperSprite* RunningFieldSprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunningField")
	int32 AmountOfRunningFieldToCreate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunningField")
	float TopLaneOffsetZ;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunningField")
	float BottomLaneOffsetZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunningField")
	FVector2D TopLaneGoalOffsetXZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunningField")
	FVector2D BottomLaneGoalOffsetXZ;
	
public:	
	ARunningField();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	
private:
	void Initialize();
	
};
