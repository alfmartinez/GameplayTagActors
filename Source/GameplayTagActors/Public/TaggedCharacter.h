// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagAssetInterface.h"
#include "TaggedCharacter.generated.h"

UCLASS()
class GAMEPLAYTAGACTORS_API ATaggedCharacter : public ACharacter, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATaggedCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// UGameplayTagAssetInterface

	/**
	 * Get any owned gameplay tags on the asset
	 *
	 * @param OutTags	[OUT] Set of tags on the asset
	 */
	UFUNCTION(BlueprintCallable, Category = GameplayTags)
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const;

	/**
	 * Check if the asset has a gameplay tag that matches against the specified tag (expands to include parents of asset tags)
	 *
	 * @param TagToCheck	Tag to check for a match
	 *
	 * @return True if the asset has a gameplay tag that matches, false if not
	 */
	UFUNCTION(BlueprintCallable, Category = GameplayTags)
	virtual bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const;

	/**
	 * Check if the asset has gameplay tags that matches against all of the specified tags (expands to include parents of asset tags)
	 *
	 * @param TagContainer			Tag container to check for a match
	 *
	 * @return True if the asset has matches all of the gameplay tags, will be true if container is empty
	 */
	UFUNCTION(BlueprintCallable, Category = GameplayTags)
	virtual bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const;

	/**
	 * Check if the asset has gameplay tags that matches against any of the specified tags (expands to include parents of asset tags)
	 *
	 * @param TagContainer			Tag container to check for a match
	 *
	 * @return True if the asset has matches any of the gameplay tags, will be false if container is empty
	 */
	UFUNCTION(BlueprintCallable, Category = GameplayTags)
	virtual bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const;

public: 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = GameplayTags)
	FGameplayTagContainer OwnedTags;
};
