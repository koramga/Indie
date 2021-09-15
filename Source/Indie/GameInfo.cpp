// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInfo.h"
#include "Controller/User/UserPlayerController.h"
#include "Pawn/PawnCharacter.h"

DEFINE_LOG_CATEGORY(UE8)

void PrintViewport(float Duration, const FColor& Color, const FString& strText)
{
	GEngine->AddOnScreenDebugMessage(-1, Duration, Color, strText);
}

void PlaySoundAtLocation(UWorld* World, USoundBase* Sound, const FVector& Location)
{
	if (IsValid(World)
		&& IsValid(Sound))
	{
		AUserPlayerController* MainPlayerController = Cast<AUserPlayerController>(UGameplayStatics::GetPlayerController(World, 0));

		if (IsValid(MainPlayerController))
		{
			APawnCharacter* PawnCharacter = MainPlayerController->GetPawn<APawnCharacter>();

			if (IsValid(PawnCharacter))
			{
				float Volumn = 1.f;

				FVector PlayerLocation = PawnCharacter->GetActorLocation();

				float Distance = FVector::Distance(PlayerLocation, Location);

				Volumn -= (1.f / 2000.f * Distance);

				UGameplayStatics::PlaySoundAtLocation(World, Sound, PawnCharacter->GetActorLocation(), Volumn);
			}
		}
	}
}

void PlaySoundAtLocation(APawnCharacter* PawnCharacter, USoundBase* Sound)
{
	return PlaySoundAtLocation(PawnCharacter->GetWorld(), Sound, PawnCharacter->GetActorLocation());
}