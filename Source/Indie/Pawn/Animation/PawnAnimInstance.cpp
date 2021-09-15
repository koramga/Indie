// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnAnimInstance.h"

UPawnAnimInstance::UPawnAnimInstance()
{
	m_PawnAnimType = EPawnAnimType::Idle;
}

void UPawnAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	m_PawnAnimState = NewObject<UPawnAnimState>(this, UPawnAnimState::StaticClass());

	for (int i = 0; i < static_cast<int>(EPawnAnimType::Max); ++i)
	{
		m_PawnAnimState->CreateAnimationState(static_cast<EPawnAnimType>(i));
	}
}

void UPawnAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void UPawnAnimInstance::SetPawnAnimType(EPawnAnimType PawnAnimType, bool EndAnimationStateOffset)
{
	if (EPawnAnimType::Death != PawnAnimType)
	{
		if (EndAnimationStateOffset)
		{
			m_PawnAnimType = PawnAnimType;
		}
		else
		{
			if (EPawnAnimType::Walk == PawnAnimType
				|| EPawnAnimType::Run == PawnAnimType)
			{
				if (EPawnAnimType::Idle == m_PawnAnimType
					|| EPawnAnimType::Walk == m_PawnAnimType
					|| EPawnAnimType::Run == m_PawnAnimType)

				{
					m_PawnAnimType = PawnAnimType;
				}
			}
			else if (EPawnAnimType::Idle == PawnAnimType)
			{
				if (EPawnAnimType::Walk == m_PawnAnimType
					|| EPawnAnimType::Run == m_PawnAnimType)
				{
					m_PawnAnimType = PawnAnimType;
				}
			}
			else
			{
				if (EPawnAnimType::Idle == m_PawnAnimType
					|| EPawnAnimType::Walk == m_PawnAnimType
					|| EPawnAnimType::Run == m_PawnAnimType)
				{
					m_PawnAnimType = PawnAnimType;
				}
			}
		}
	}
}

void UPawnAnimInstance::SetAngle(float Angle)
{
	m_Angle = Angle;
}

void UPawnAnimInstance::SetSpeed(float Speed)
{
	m_Speed = Speed;
}

EPawnAnimType UPawnAnimInstance::GetPawnAnimType() const
{
	return m_PawnAnimType;
}

float UPawnAnimInstance::GetAngle() const
{
	return m_Angle;
}

float UPawnAnimInstance::GetSpeed() const
{
	return m_Speed;
}

void UPawnAnimInstance::AddEndAnimationState(EPawnAnimType PawnAnimType)
{
	m_PawnAnimState->AddEndAnimationState(PawnAnimType);
}

void UPawnAnimInstance::SetEndAnimationState(EPawnAnimType PawnAnimType, EPawnAnimType NextPawnAnimType)
{
	m_PawnAnimState->SetEndAnimationState(PawnAnimType);

	//끝이났으니까

	SetPawnAnimType(NextPawnAnimType, true);
}

void UPawnAnimInstance::ResetAnimationState(EPawnAnimType PawnAnimType)
{
	m_PawnAnimState->ResetAnimationState(PawnAnimType);
}

void UPawnAnimInstance::SetAnimationStateEndCount(EPawnAnimType PawnAnimType, int32 Count)
{
	m_PawnAnimState->SetAnimationStateEndCount(PawnAnimType, Count);
}