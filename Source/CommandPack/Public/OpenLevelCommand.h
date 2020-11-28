// Gradess & Novaturion Company. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseCommand.h"
#include "OpenLevelCommand.generated.h"


/**
 * 
 */
UCLASS()
class COMMANDPACK_API UOpenLevelCommand : public UBaseCommand
{
	GENERATED_BODY()

	static FString DefaultOptions;

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Command Pack", meta=(AdvancedDisplay=1))
	bool Init(
		UPARAM(DisplayName="WorldContextObject") UObject* InWorldContextObject,
		UPARAM(DisplayName="LevelName") FName InLevelName,
		UPARAM(DisplayName="Absolute") bool bInAbsolute,
		UPARAM(DisplayName="Options") FString& InOptions
	);
	virtual bool Init_Implementation(
		UObject* InWorldContextObject,
		FName InLevelName,
		bool bInAbsolute = true,
		FString& InOptions = DefaultOptions
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
