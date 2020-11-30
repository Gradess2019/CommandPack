// Gradess & Novaturion Company. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseCommand.h"
#include "OpenLevelCommand.generated.h"


/**
 * Command to open level
 */
UCLASS()
class COMMANDPACK_API UOpenLevelCommand : public UBaseCommand
{
	GENERATED_BODY()

	static FString DefaultOptions;

public:

	UFUNCTION(
		BlueprintCallable,
		BlueprintNativeEvent,
		Category = "Command Pack | Open Level Command",
		meta=(AdvancedDisplay = 1, WorldContext = "InWorldContextObject", CallableWithoutWorldContext)
	)
	bool Init(
		UPARAM(DisplayName="WorldContextObject") UObject* InWorldContextObject,
		UPARAM(DisplayName="LevelName") FName InLevelName,
		UPARAM(DisplayName="Absolute") bool bInAbsolute = true,
		UPARAM(DisplayName="Options") const FString& InOptions = FString(TEXT(""))
	);

	virtual void Execute_Implementation() override;

protected:

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Open Level Command")
	FName LevelName;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Open Level Command")
	bool bAbsolute;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Open Level Command")
	FString Options;
};
