// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../GameInfo.h"
#include "GameFramework/PlayerController.h"
#include "UserPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class INDIE_API AUserPlayerController : public APlayerController
{
	GENERATED_BODY()

public :
	AUserPlayerController();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	class APlayerCharacter* m_PlayerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	TSubclassOf<UMatineeCameraShake>	m_CameraShake;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	/**
	 * Processes player input (immediately after PlayerInput gets ticked) and calls UpdateRotation().
	 * PlayerTick is only called if the PlayerController has a PlayerInput object. Therefore, it will only be called for locally controlled PlayerControllers.
	 */
	virtual void PlayerTick(float DeltaTime);

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

public :
	void CameraShake();
	
};
