// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../GameInfo.h"
#include "../PawnCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class INDIE_API APlayerCharacter : public APawnCharacter
{
	GENERATED_BODY()

public :
	APlayerCharacter();

protected :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	UCameraComponent* m_Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	USpringArmComponent* m_Arm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	UStaticMeshComponent* m_LHandMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	UStaticMeshComponent* m_RHandMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	class UPlayerAnimInstance* m_PlayerAnimInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	EToggleWalkAndRun	m_ToggleWalkAndRun;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	bool m_DilationToggle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private :
	void __InputMoveForwardBack(float Scale);
	void __InputMoveLeftRight(float Scale);
	void __InputAttackTypeKey(float Scale);
	void __InputComboTypeKey(float Scale);
	void __InputToggleWalkAndRun();
	void __InputToggleKey();
	void __InputDefenceKey();
	void __InputAttackKey();
	void __InputForwardAvoidKey();
	void __InputBackAvoidKey();
	void __InputLeftAvoidKey();
	void __InputRightAvoidKey();

public :
	void AddArmPitch(float Value);
	void SetPlayerWeaponType(EPlayerWeaponType PlayerWeaponType);

public :
	virtual bool CanMove();
	virtual void UpdateMoveAnimation();
};
