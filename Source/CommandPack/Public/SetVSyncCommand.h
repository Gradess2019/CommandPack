// Gradess & Novaturion Company. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseCommand.h"
#include "SetVSyncCommand.generated.h"

/**
 * Command to set VSync state
 */
UCLASS()
class COMMANDPACK_API USetVSyncCommand : public UBaseCommand
{
	GENERATED_BODY()


public:

	UFUNCTION(
		BlueprintCallable,
		BlueprintNativeEvent,
		Category = "Command Pack | Set VSync Command",
		meta=(AdvancedDisplay=2)
	)
	bool Init(
		UPARAM(DisplayName="WorldContextObject") UObject* InWorldContextObject,
		UPARAM(DisplayName="Enable") bool bInEnable = true,
		UPARAM(DisplayName="CheckForCommandLineOverrides") bool bInCheckCommandLineOverrides = true
	);

	virtual void Execute_Implementation() override;

protected:

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Set VSync Command")
	bool bEnable;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Set VSync Command")
	bool bCheckCommandLineOverrides;
};
