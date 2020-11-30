// Gradess & Novaturion Company. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseCommand.h"
#include "Kismet/KismetSystemLibrary.h"

#include "QuitCommand.generated.h"

/**
 * Base command for quit game
 */
UCLASS()
class COMMANDPACK_API UQuitCommand : public UBaseCommand
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Command Pack", meta=(AdvancedDisplay=1))
	bool Init(
		UObject* InWorldContextObject,
		APlayerController* InSpecificPlayer,
		EQuitPreference::Type InQuitPreference,
		bool bInIgnorePlatformRestrictions
	);
	virtual bool Init_Implementation(
		UObject* InWorldContextObject,
		APlayerController* InSpecificPlayer = nullptr,
		EQuitPreference::Type InQuitPreference = EQuitPreference::Quit,
		bool bInIgnorePlatformRestrictions = false
	);

	virtual void Execute_Implementation() override;

protected:

	APlayerController* PlayerController;

	TEnumAsByte<EQuitPreference::Type> QuitPreference;

	bool bIgnorePlatformRestrictions;
};
