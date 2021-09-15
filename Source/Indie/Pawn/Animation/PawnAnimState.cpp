// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnAnimState.h"

UPawnAnimState::UPawnAnimState()
{

}

bool UPawnAnimState::CreateAnimationState(EPawnAnimType PawnAnimType)
{
	UPawnAnimStateData* PawnAnimStateData = m_mapPawnAnimStateData.FindRef(PawnAnimType);

	if (IsValid(PawnAnimStateData))
	{
		return false;
	}

	PawnAnimStateData = NewObject<UPawnAnimStateData>(this, UPawnAnimStateData::StaticClass());

	PawnAnimStateData->SetPawnAnimType(PawnAnimType);
	PawnAnimStateData->SetPawnAnimState(EPawnAnimState::None);
	PawnAnimStateData->SetEndCount(1);

	m_mapPawnAnimStateData.Add(PawnAnimType, PawnAnimStateData);

	return true;
}

void UPawnAnimState::SetAnimationStateEndCount(EPawnAnimType PawnAnimType, int32 Count)
{
	UPawnAnimStateData* PawnAnimStateData = m_mapPawnAnimStateData.FindRef(PawnAnimType);

	if (IsValid(PawnAnimStateData))
	{
		PawnAnimStateData->SetEndCount(Count);
	}
}

void UPawnAnimState::SetStartAnimationState(EPawnAnimType PawnAnimType)
{
	UPawnAnimStateData* PawnAnimStateData = m_mapPawnAnimStateData.FindRef(PawnAnimType);

	if (IsValid(PawnAnimStateData))
	{
		PawnAnimStateData->SetPawnAnimState(EPawnAnimState::Start);
	}
}

void UPawnAnimState::AddEndAnimationState(EPawnAnimType PawnAnimType)
{
	UPawnAnimStateData* PawnAnimStateData = m_mapPawnAnimStateData.FindRef(PawnAnimType);

	if (IsValid(PawnAnimStateData))
	{
		if (EPawnAnimState::Start == PawnAnimStateData->GetPawnAnimState())
		{
			PawnAnimStateData->AddCount();

			if (PawnAnimStateData->GetCount() >= PawnAnimStateData->GetEndCount())
			{
				PawnAnimStateData->SetPawnAnimState(EPawnAnimState::CountEnd);
			}
		}
	}
}

void UPawnAnimState::SetEndAnimationState(EPawnAnimType PawnAnimType)
{
	UPawnAnimStateData* PawnAnimStateData = m_mapPawnAnimStateData.FindRef(PawnAnimType);

	if (IsValid(PawnAnimStateData))
	{
		if (EPawnAnimState::None != PawnAnimStateData->GetPawnAnimState())
		{
			PawnAnimStateData->SetPawnAnimState(EPawnAnimState::End);
		}
	}
}

void UPawnAnimState::ResetAnimationState(EPawnAnimType PawnAnimType)
{
	UPawnAnimStateData* PawnAnimStateData = m_mapPawnAnimStateData.FindRef(PawnAnimType);

	if (IsValid(PawnAnimStateData))
	{
		PawnAnimStateData->SetPawnAnimState(EPawnAnimState::None);
		PawnAnimStateData->ResetCount();
	}
}

EPawnAnimState UPawnAnimState::GetAnimationState(EPawnAnimType PawnAnimType)
{
	UPawnAnimStateData* PawnAnimStateData = m_mapPawnAnimStateData.FindRef(PawnAnimType);

	if (IsValid(PawnAnimStateData))
	{
		return PawnAnimStateData->GetPawnAnimState();
	}

	return EPawnAnimState::Max;
}

bool UPawnAnimState::IsFinishAnimationState(EPawnAnimType PawnAnimType) const
{
	UPawnAnimStateData* PawnAnimStateData = m_mapPawnAnimStateData.FindRef(PawnAnimType);

	if (IsValid(PawnAnimStateData))
	{
		return PawnAnimStateData->IsFinishAnimation();
	}

	return false;
}