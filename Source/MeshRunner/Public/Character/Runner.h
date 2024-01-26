// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Runner.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UPaperFlipbook;

UCLASS()
class MESHRUNNER_API ARunner : public APaperCharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runner|Speed")
	float MaxSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runner|Speed")
	float SpeedIncreasePerTab;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runner|Speed")
	float SpeedDecreasePerTickWithDelta;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runner|Speed")
	UCurveFloat* SpeedIncreaseRampCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runner|Speed")
	UCurveFloat* SpeedDecreaseRampCurve;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runner|Flipbook")
	UPaperFlipbook* IdleFlipbook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runner|Flipbook")
	UPaperFlipbook* RunFlipbook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runner|Sound")
	USoundBase* FootstepSoundCue;

private:
	int32 LastFrame;
	
public:
    ARunner();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaSeconds) override;

public:
	void IncreaseSpeed() const;
	
};
