// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RunnerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class MESHRUNNER_API ARunnerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runner")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runner")
	UInputAction* LeftAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runner")
	UInputAction* RightAction;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void InputLeftKey();
	void InputRightKey();
	
};
