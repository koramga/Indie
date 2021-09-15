// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnAnimStateData.h"

void UPawnAnimStateData::SetPawnAnimType(EPawnAnimType PawnAnimType)
{
    m_PawnAnimType = PawnAnimType;
}

void UPawnAnimStateData::SetPawnAnimState(EPawnAnimState PawnAnimState)
{
    m_PawnAnimState = PawnAnimState;
}

void UPawnAnimStateData::SetEndCount(int32 Count)
{
    m_EndCount = Count;
}

void UPawnAnimStateData::AddCount()
{
    m_Count++;
}

bool UPawnAnimStateData::IsFinishAnimation() const
{
    if (m_Count >= m_EndCount)
    {
        return true;
    }

    return false;
}

void UPawnAnimStateData::ResetCount()
{
    m_Count = 0;
}

