// Fill out your copyright notice in the Description page of Project Settings.


#include "TaggedCharacter.h"

// Sets default values
ATaggedCharacter::ATaggedCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATaggedCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATaggedCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATaggedCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATaggedCharacter::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = OwnedTags;
}

bool ATaggedCharacter::HasMatchingGameplayTag(FGameplayTag TagToCheck) const
{
	return OwnedTags.HasTagExact(TagToCheck);
}

bool ATaggedCharacter::HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	return OwnedTags.HasAllExact(TagContainer);
}

bool ATaggedCharacter::HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	return OwnedTags.HasAnyExact(TagContainer);
}

