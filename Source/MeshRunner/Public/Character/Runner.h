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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runner")
	UPaperFlipbook* IdleFlipbook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runner")
	UPaperFlipbook* RunFlipbook;

	
	
public:
    ARunner();
	
};
