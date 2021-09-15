// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../GameInfo.h"
#include "PawnAnimStateData.h"
#include "UObject/NoExportTypes.h"
#include "PawnAnimState.generated.h"

/**
 * 
 */
UCLASS()
class INDIE_API UPawnAnimState : public UObject
{
	GENERATED_BODY()

public:
	UPawnAnimState();

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	TMap<EPawnAnimType, UPawnAnimStateData*>	m_mapPawnAnimStateData;

public:
	bool CreateAnimationState(EPawnAnimType PawnAnimType);

public:
	void SetAnimationStateEndCount(EPawnAnimType PawnAnimType, int32 Count);
	void SetStartAnimationState(EPawnAnimType PawnAnimType);
	void AddEndAnimationState(EPawnAnimType PawnAnimType);
	void SetEndAnimationState(EPawnAnimType PawnAnimType);
	void ResetAnimationState(EPawnAnimType PawnAnimType);
	EPawnAnimState GetAnimationState(EPawnAnimType PawnAnimType);

public:
	bool IsFinishAnimationState(EPawnAnimType PawnCharacterAnimationType) const;
	
};
