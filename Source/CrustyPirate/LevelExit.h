// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"
#include "PaperFlipbookComponent.h"

#include "Sound/SoundBase.h"
#include "Engine/TimerHandle.h"

#include "LevelExit.generated.h"

UCLASS()
class CRUSTYPIRATE_API ALevelExit : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UBoxComponent* BoxComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UPaperFlipbookComponent* DoorFlipbook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* PlayerEnterSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LevelIndex = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WaitTimeInSeconds = 2.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsActive = true;

	FTimerHandle WaitTimer;

	ALevelExit();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void OnWaitTimerTimeout();
};
