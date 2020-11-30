// Gradess & Novaturion Company. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseCommand.generated.h"

/**
 * Base class for implementing Command pattern
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class COMMANDPACK_API UBaseCommand : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Command Pack")
	bool InitWorldContext(UObject* InWorldContextObject);
	virtual bool InitWorldContext_Implementation(UObject* InWorldContextObject);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Command Pack")
	void Execute();
	virtual void Execute_Implementation();

protected:

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack")
	UObject* WorldContextObject;
};
