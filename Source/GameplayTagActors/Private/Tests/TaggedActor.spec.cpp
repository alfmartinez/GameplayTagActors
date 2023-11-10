#include "TaggedActor.h"
#include "NativeGameplayTags.h"


UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_TEST_ADDED, "Test.Added"); 
UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_TEST_EXISTING, "Test.Existing");
UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_TEST_OTHER, "Test.Other");

BEGIN_DEFINE_SPEC(
    FTaggedActorSpec, "Plugins.GameplayTagActors",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
END_DEFINE_SPEC(FTaggedActorSpec)

void FTaggedActorSpec::Define()
{
    Describe("Tagged Actor", [this]() {
        Describe("GetOwnedGameplayTags", [this]()
            {
                It("should return a copy of OwnedTags", [this]()
                    {
                        ATaggedActor* TaggedActor = NewObject<ATaggedActor>();
                        FGameplayTagContainer Tags;
                        TaggedActor->OwnedTags.AddTag(TAG_TEST_EXISTING);
                        TaggedActor->GetOwnedGameplayTags(Tags);
                        TaggedActor->OwnedTags.AddTag(TAG_TEST_ADDED);

                        TestFalse("shouldn't have added tag", Tags.HasTagExact(TAG_TEST_ADDED));
                        TestTrue("should have existing tag", Tags.HasTagExact(TAG_TEST_EXISTING));
                    });
            });

        Describe("HasMatchingGameplayTag", [this]()
            {
                It("should return true if tag is present", [this]()
                    {
                        ATaggedActor* TaggedActor = NewObject<ATaggedActor>();
                        TaggedActor->OwnedTags.AddTag(TAG_TEST_ADDED);

                        TestTrue("should have added tag", TaggedActor->HasMatchingGameplayTag(TAG_TEST_ADDED));
                    });

                It("should return false if tag is not present", [this]()
                    {
                        ATaggedActor* TaggedActor = NewObject<ATaggedActor>();
                        TaggedActor->OwnedTags.AddTag(TAG_TEST_EXISTING);

                        TestFalse("shouldn't have added tag", TaggedActor->HasMatchingGameplayTag(TAG_TEST_ADDED));
                    });
            });
        Describe("HasAllMatchingGameplayTags", [this]()
            {
                It("should return true if all tags are present", [this]()
                    {
                        ATaggedActor* TaggedActor = NewObject<ATaggedActor>();
                        TaggedActor->OwnedTags.AddTag(TAG_TEST_ADDED);
                        TaggedActor->OwnedTags.AddTag(TAG_TEST_EXISTING);

                        FGameplayTagContainer ExpectedTags(TAG_TEST_EXISTING);
                        ExpectedTags.AddTag(TAG_TEST_ADDED);

                        TestTrue("all tags should be here", TaggedActor->HasAllMatchingGameplayTags(ExpectedTags));
                    });

                It("should return false if tag is not present", [this]()
                    {
                        ATaggedActor* TaggedActor = NewObject<ATaggedActor>();
                        TaggedActor->OwnedTags.AddTag(TAG_TEST_ADDED);
                        TaggedActor->OwnedTags.AddTag(TAG_TEST_EXISTING);

                        FGameplayTagContainer ExpectedTags(TAG_TEST_EXISTING);
                        ExpectedTags.AddTag(TAG_TEST_ADDED);
                        ExpectedTags.AddTag(TAG_TEST_OTHER);

                        TestFalse("a tag should be missing", TaggedActor->HasAllMatchingGameplayTags(ExpectedTags));
                    });
            });

        Describe("HasAnyMatchingGameplayTags", [this]() 
            {
                It("should return true if any tag is present", [this]()
                    {
                        ATaggedActor* TaggedActor = NewObject<ATaggedActor>();
                        TaggedActor->OwnedTags.AddTag(TAG_TEST_ADDED);
                        
                        FGameplayTagContainer ExpectedTags(TAG_TEST_EXISTING);
                        ExpectedTags.AddTag(TAG_TEST_ADDED);

                        TestTrue("any tag should be here", TaggedActor->HasAnyMatchingGameplayTags(ExpectedTags));
                    });

                It("should return false if no matching tag is present", [this]()
                    {
                        ATaggedActor* TaggedActor = NewObject<ATaggedActor>();
                        TaggedActor->OwnedTags.AddTag(TAG_TEST_ADDED);
                        TaggedActor->OwnedTags.AddTag(TAG_TEST_EXISTING);

                        FGameplayTagContainer ExpectedTags(TAG_TEST_OTHER);

                        TestFalse("no matching tag should be found", TaggedActor->HasAnyMatchingGameplayTags(ExpectedTags));
                    });
            });
    });
    


}

