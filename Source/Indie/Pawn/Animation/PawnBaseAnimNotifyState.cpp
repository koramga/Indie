// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnBaseAnimNotifyState.h"
#include "../PawnCharacter.h"

UPawnBaseAnimNotifyState::UPawnBaseAnimNotifyState()
{

}

void UPawnBaseAnimNotifyState::AddLoopAnimationSequence(const FName& Name, const FString& SoundPath)
{
	UPawnBaseAnimNotifyStateData* NewData = NewObject<UPawnBaseAnimNotifyStateData>(this, UPawnBaseAnimNotifyStateData::StaticClass());

	if (IsValid(NewData))
	{
		NewData->SetSequenceName(Name);

		if (false == SoundPath.IsEmpty())
		{
			NewData->SetSoundPath(SoundPath);
		}

		m_LoopAnimationSequenceData.Add(NewData);
	}
}

void UPawnBaseAnimNotifyState::AddEndAnimationSequence(const FName& Name, const FString& SoundPath)
{
	UPawnBaseAnimNotifyStateData* NewData = NewObject<UPawnBaseAnimNotifyStateData>(this, UPawnBaseAnimNotifyStateData::StaticClass());

	if (IsValid(NewData))
	{
		NewData->SetSequenceName(Name);

		if (false == SoundPath.IsEmpty())
		{
			NewData->SetSoundPath(SoundPath);
		}

		m_EndAnimationSequenceData.Add(NewData);
	}
}

void UPawnBaseAnimNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);

	APawnCharacter* PawnCharacter = MeshComp->GetOwner<APawnCharacter>();
	FVector SoundLocation = FVector::ZeroVector;

	if (IsValid(PawnCharacter))
	{
		m_PawnAnimType = PawnCharacter->GetPawnAnimType();
	}

	FString strSequenceName = Animation->GetName();
	FName SequenceName = FName(*strSequenceName);

	LOG(TEXT("NotifyBegin : %s"), *SequenceName.ToString());

	m_HasLoopAnimation = false;
	m_HasEndAnimation = false;

	for (UPawnBaseAnimNotifyStateData* SequenceData : m_LoopAnimationSequenceData)
	{
		if (SequenceData->GetSequenceName() == SequenceName)
		{
			m_HasLoopAnimation = true;

			m_SequenceData = SequenceData;

			break;
		}
	}

	//LOG(TEXT("SequenceName <%s>"), *strSequenceName);

	for (UPawnBaseAnimNotifyStateData* SequenceData : m_EndAnimationSequenceData)
	{
		if (SequenceData->GetSequenceName() == SequenceName)
		{
			m_HasEndAnimation = true;

			m_SequenceData = SequenceData;

			break;
		}
	}

	if (IsValid(m_SequenceData))
	{
		m_SequenceData->PlaySound(PawnCharacter);
	}
}

void UPawnBaseAnimNotifyState::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime);

	if (m_HasLoopAnimation)
	{
		m_DeltaTime += FrameDeltaTime;

		APawnCharacter* PawnCharacter = MeshComp->GetOwner<APawnCharacter>();

		if (IsValid(PawnCharacter))
		{
			if (m_DeltaTime >= Animation->GetPlayLength())
			{
				m_DeltaTime -= Animation->GetPlayLength();

				if (IsValid(m_SequenceData))
				{
					m_SequenceData->PlaySound(PawnCharacter);
				}

				PawnCharacter->AddEndAnimationState(m_PawnAnimType);
			}
		}
	}
}

void UPawnBaseAnimNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);

	if (IsValid(Animation))
	{
		LOG(TEXT("NotifyEnd : %s"), *Animation->GetName());
	}

	if (m_HasEndAnimation)
	{
		APawnCharacter* PawnCharacter = MeshComp->GetOwner<APawnCharacter>();

		if (IsValid(PawnCharacter))
		{
			PawnCharacter->SetEndAnimationState(m_PawnAnimType);
		}
	}
}
