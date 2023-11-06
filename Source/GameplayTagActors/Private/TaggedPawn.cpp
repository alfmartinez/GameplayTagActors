// Fill out your copyright notice in the Description page of Project Settings.


#include "TaggedPawn.h"

// Sets default values
ATaggedPawn::ATaggedPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATaggedPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATaggedPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATaggedPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATaggedPawn::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = OwnedTags;
}

bool ATaggedPawn::HasMatchingGameplayTag(FGameplayTag TagToCheck) const
{
	return OwnedTags.HasTagExact(TagToCheck);
}

bool ATaggedPawn::HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	return OwnedTags.HasAllExact(TagContainer);
}

bool ATaggedPawn::HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	return OwnedTags.HasAnyExact(TagContainer);
}

