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
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunningField")
	UPaperSprite* RunningFieldSprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunningField")
	int32 AmountOfRunningFieldToCreate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunningField")
	float TopLaneOffsetZ;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunningField")
	float BottomLaneOffsetZ;
	
public:	
	ARunningField();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;

};
