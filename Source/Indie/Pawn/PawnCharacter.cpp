// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnCharacter.h"
#include "Animation/PawnAnimInstance.h"
// Sets default values
APawnCharacter::APawnCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APawnCharacter::BeginPlay()
{
	Super::BeginPlay();

	m_PawnAnimInstance = Cast<UPawnAnimInstance>(GetMesh()->GetAnimInstance());
}

// Called every frame
void APawnCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UCharacterMovementComponent* pMovement = GetCharacterMovement();

	FVector vForward = GetActorForwardVector();
	FVector vVelocity = pMovement->Velocity;

	m_Speed = vVelocity.Size();

	if (m_Speed > 0)
	{
		//https://amored8701.tistory.com/132

		vForward.Z = 0.f;
		vVelocity.Z = 0.f;

		vForward.Normalize();
		vVelocity.Normalize();

		float fDot = FVector::DotProduct(vForward, vVelocity);
		float fAcosAngle = FMath::Acos(fDot);
		float fAngle = FMath::RadiansToDegrees(fAcosAngle);

		//if (fDot < -0.3f)
		//{
		//	m_Speed *= -1.f;
		//}

		FVector vCross = FVector::CrossProduct(vForward, vVelocity);

		if (vCross.Z < 0)
		{
			//fAngle *= -1.f;
			fAngle = 360 - fAngle;
		}

		m_Angle = fAngle;

		//PrintViewport(1.f, FColor::Red, FString::Printf(TEXT("%.2f %.2f"), m_Angle, m_Speed));
	}

	m_PawnAnimInstance->SetSpeed(m_Speed);
	m_PawnAnimInstance->SetAngle(m_Angle);
	m_PawnAnimInstance->SetAttackType(m_AttackType);
	m_PawnAnimInstance->SetComboType(m_ComboType);
}

EPawnAnimType APawnCharacter::GetPawnAnimType() const
{
	return m_PawnAnimInstance->GetPawnAnimType();
}

void APawnCharacter::AddEndAnimationState(EPawnAnimType PawnCharacterAnimType)
{
	m_PawnAnimInstance->AddEndAnimationState(PawnCharacterAnimType);
}

void APawnCharacter::SetEndAnimationState(EPawnAnimType PawnCharacterAnimType)
{
	m_PawnAnimInstance->SetEndAnimationState(PawnCharacterAnimType);
}

void APawnCharacter::ResetAnimationState(EPawnAnimType PawnCharacterAnimType)
{
	m_PawnAnimInstance->ResetAnimationState(PawnCharacterAnimType);
}

void APawnCharacter::SetAnimationStateEndCount(EPawnAnimType PawnCharacterAnimType, int32 Count)
{
	m_PawnAnimInstance->SetAnimationStateEndCount(PawnCharacterAnimType, Count);
}