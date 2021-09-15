// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../Animation/PawnBaseAnimNotifyState.h"
#include "PlayerBaseAnimNotifyState.generated.h"

/**
 * 
 */
UCLASS()
class INDIE_API UPlayerBaseAnimNotifyState : public UPawnBaseAnimNotifyState
{
	GENERATED_BODY()

public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration);
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime);
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation);	
};
