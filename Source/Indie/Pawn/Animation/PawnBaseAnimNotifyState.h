// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../GameInfo.h"
#include "PawnBaseAnimNotifyStateData.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "PawnBaseAnimNotifyState.generated.h"

/**
 * 
 */
UCLASS()
class INDIE_API UPawnBaseAnimNotifyState : public UAnimNotifyState
{
	GENERATED_BODY()

public :
	UPawnBaseAnimNotifyState();

protected :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	EPawnAnimType	m_PawnAnimType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	float					m_DeltaTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	TArray<UPawnBaseAnimNotifyStateData*>		m_EndAnimationSequenceData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	TArray<UPawnBaseAnimNotifyStateData*>		m_LoopAnimationSequenceData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	bool					m_HasLoopAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	bool					m_HasEndAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	UPawnBaseAnimNotifyStateData* m_SequenceData;
	
protected:
	void AddLoopAnimationSequence(const FName& Name, const FString& SoundPath = TEXT(""));
	void AddEndAnimationSequence(const FName& Name, const FString& SoundPath = TEXT(""));

public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration);
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime);
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation);	
};
