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