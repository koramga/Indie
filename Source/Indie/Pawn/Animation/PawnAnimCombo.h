// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../GameInfo.h"
#include "UObject/NoExportTypes.h"
#include "PawnAnimCombo.generated.h"

/**
 * 
 */
UCLASS()
class INDIE_API UPawnAnimCombo : public UObject
{
	GENERATED_BODY()

public :
	UPawnAnimCombo();

protected :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	UAnimMontage*		m_ComboMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	bool				m_EnableUpdateMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	int32				m_ComboIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	int32				m_ComboCount;

public :
	static FName GetComboStartName(int32 ComboIndex);
	static FName GetComboEndeName(int32 ComboIndex);
	
public :
	void SetAnimMontage(UAnimMontage* AnimMontage, int32 ComboCount);
	void StartAnimMontage(UAnimInstance* AnimInstance);
	void UpdateAnimMontage(UAnimInstance* AnimInstance);

public :
	void SetEnableUpdateAnimMontage(bool EnableUpdateAnimMontage);

public :
	bool IsEnableUpdateAnimMontage() const;
};
