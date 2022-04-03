// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameModeBase.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAllGameModeBase::PawnKilled(APawn* PawnKilled)
{
	Super:: PawnKilled(PawnKilled);
	
	//win or lose scenario
	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	
	//game over loses
	if (PlayerController != nullptr)
	{
		//PlayerController->GameHasEnded(nullptr, false);
		EndGame(false);
	}

	//Is AI dead?
	for (AShooterAIController* AIController : TActorRange<AShooterAIController>(GetWorld()))
	{
		//if not continue game
		if (!AIController->isDead())
		{
			return;
		}
	}

	//if they are end game
	EndGame(true);
}

//will notify ai that game has ended
void AKillEmAllGameModeBase::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld())) 
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}
