// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../GameInfo.h"
#include "UObject/NoExportTypes.h"
#include "PawnBaseAnimNotifyStateData.generated.h"

/**
 * 
 */
UCLASS()
class INDIE_API UPawnBaseAnimNotifyStateData : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FName			m_SequenceName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	USoundBase*		m_Sound;

public:
	void SetSequenceName(const FName& Name);
	void SetSoundPath(const FString& Path);

public:
	FName GetSequenceName() const;
	USoundBase* GetSound() const;
	void PlaySound(UWorld* World, const FVector& Location);
	void PlaySound(class APawnCharacter* PawnCharacter);
};
