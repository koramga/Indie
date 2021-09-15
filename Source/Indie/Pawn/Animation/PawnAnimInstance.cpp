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
	m_PawnAnimCombo = NewObject<UPawnAnimCombo>(this, UPawnAnimCombo::StaticClass());

	for (int i = 0; i < static_cast<int>(EPawnAnimType::Max); ++i)
	{
		m_PawnAnimState->CreateAnimationState(static_cast<EPawnAnimType>(i));
	}
}

void UPawnAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void UPawnAnimInstance::AnimNotify_EnableCombo()
{
	m_PawnAnimCombo->SetEnableUpdateAnimMontage(true);
}

void UPawnAnimInstance::AnimNotify_DisableCombo()
{
	m_PawnAnimCombo->SetEnableUpdateAnimMontage(false);
}

void UPawnAnimInstance::UpdatePawnType(EPawnAnimType BeforePawnAnimType, EPawnAnimType AfterPawnAnimType)
{

}

void UPawnAnimInstance::UpdateAnimCombo(UPawnAnimCombo* PawnAnimCombo, int32 AttackType, int32 ComboType)
{

}

void UPawnAnimInstance::SetPawnAnimType(EPawnAnimType PawnAnimType, bool EndAnimationStateOffset)
{
	EPawnAnimType BeforePawnAnimType = m_PawnAnimType;

	if (EPawnAnimType::Death != PawnAnimType)
	{
		if (EndAnimationStateOffset)
		{
			m_PawnAnimType = PawnAnimType;
		}
		else
		{
			if (m_PawnAnimCombo->IsEnableUpdateAnimMontage())
			{
				if (EPawnAnimType::Attack == PawnAnimType)
				{
					//Combo되었다!
					m_PawnAnimCombo->UpdateAnimMontage(this);
				}
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

	if (BeforePawnAnimType != m_PawnAnimType)
	{
		UpdatePawnType(BeforePawnAnimType, m_PawnAnimType);

		if (EPawnAnimType::Attack == m_PawnAnimType)
		{
			if (m_ComboType > 0)
			{
				//추출한다.
				UpdateAnimCombo(m_PawnAnimCombo, m_AttackType, m_ComboType);
				m_PawnAnimCombo->StartAnimMontage(this);
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

void UPawnAnimInstance::SetAttackType(int32 AttackType)
{
	if (EPawnAnimType::Attack != m_PawnAnimType)
	{
		m_AttackType = AttackType;
	}
}

void UPawnAnimInstance::SetComboType(int32 ComboType)
{
	if (EPawnAnimType::Attack != m_PawnAnimType)
	{
		m_ComboType = ComboType;
	}
}

void UPawnAnimInstance::SetDirection(EDirection Direction)
{
	if (EPawnAnimType::Avoid != m_PawnAnimType)
	{
		m_Direction = Direction;
	}
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

int32 UPawnAnimInstance::GetAttackType() const
{
	return m_AttackType;
}

int32 UPawnAnimInstance::GetComboType() const
{
	return m_ComboType;
}

EDirection UPawnAnimInstance::GetDirection() const
{
	return m_Direction;
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