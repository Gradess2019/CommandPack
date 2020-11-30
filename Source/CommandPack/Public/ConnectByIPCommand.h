// Gradess & Novaturion Company. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseCommand.h"
#include "ConnectByIPCommand.generated.h"

/**
 * 
 */
UCLASS()
class COMMANDPACK_API UConnectByIPCommand : public UBaseCommand
{
	GENERATED_BODY()

public:

	UFUNCTION(
		BlueprintCallable,
		BlueprintNativeEvent,
		Category = "Command Pack | Connect By IP Command",
		meta=(AdvancedDisplay=2)
	)
	bool Init(
		UPARAM(DisplayName="WorldContextObject") UObject* InWorldContextObject,
		UPARAM(DisplayName="IP") const FString& InIP = FString(TEXT("127.0.0.1")),
		UPARAM(DisplayName="PlayerController") APlayerController* InPlayerController = nullptr
	);

	virtual void Execute_Implementation() override;

protected:

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Connect By IP Command")
	FString IP;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Connect By IP Command")
	APlayerController* PlayerController;
};
