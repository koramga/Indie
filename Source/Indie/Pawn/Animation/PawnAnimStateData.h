// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../GameInfo.h"
#include "UObject/NoExportTypes.h"
#include "PawnAnimStateData.generated.h"

/**
 * 
 */
UCLASS()
class INDIE_API UPawnAnimStateData : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	EPawnAnimType		m_PawnAnimType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	EPawnAnimState		m_PawnAnimState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	int32				m_Count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	int32				m_EndCount;

public:
	void SetPawnAnimType(EPawnAnimType PawnAnimType);
	void SetPawnAnimState(EPawnAnimState PawnAnimState);
	void SetEndCount(int32 Count);
	void AddCount();

public:
	EPawnAnimState GetPawnAnimState() const
	{
		return m_PawnAnimState;
	}

	int32 GetCount() const
	{
		return m_Count;
	}

	int32 GetEndCount() const
	{
		return m_EndCount;
	}

public:
	bool IsFinishAnimation() const;
	void ResetCount();
	
};
