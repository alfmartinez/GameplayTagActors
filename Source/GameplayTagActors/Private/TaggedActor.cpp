// Fill out your copyright notice in the Description page of Project Settings.


#include "TaggedActor.h"

// Sets default values
ATaggedActor::ATaggedActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATaggedActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATaggedActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATaggedActor::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = OwnedTags;
}

bool ATaggedActor::HasMatchingGameplayTag(FGameplayTag TagToCheck) const
{
	return OwnedTags.HasTagExact(TagToCheck);
}

bool ATaggedActor::HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	return OwnedTags.HasAllExact(TagContainer);
}

bool ATaggedActor::HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	return OwnedTags.HasAnyExact(TagContainer);
}

