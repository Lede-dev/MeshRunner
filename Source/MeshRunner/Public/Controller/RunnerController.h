// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RunnerController.generated.h"

class AMeshRunnerGameMode;
class ARunner;
class UInputMappingContext;
class UInputAction;

UENUM()
enum class ERunnerInputType : uint8
{
	Left,
	Right
};

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
	TWeakObjectPtr<ARunner> RunnerPlayer;
	TWeakObjectPtr<AMeshRunnerGameMode> GameMode;
	
	ERunnerInputType LastInput = ERunnerInputType::Left;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void InputLeftKey();
	void InputRightKey();
	
};
