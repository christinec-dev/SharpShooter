// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SHARPSHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	//Allows us to pull trigger
	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//creates mesh object for our gun
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	//allows us to get gun skeleton to add particles
	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;

	//sounds for gun
	UPROPERTY(EditAnywhere)
	USoundBase* MuzzleSound;
	UPROPERTY(EditAnywhere)
	USoundBase *ImpactSound;

	//Bullet hit particle
	UPROPERTY(EditAnywhere)
	UParticleSystem *ImpactEffect;

	//Max range for bullet trace (10 m)
	UPROPERTY(EditAnywhere)
	float MaxRange = 2000;

	//Max damage
	UPROPERTY(EditAnywhere)
	float Damage = 10;

	bool GunTrace(FHitResult &Hit, FVector& ShotDirection);
	AController* GetOwnerController() const;
};
