// Gradess & Novaturion Company. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseCommand.h"
#include "CreateWidgetCommand.generated.h"

USTRUCT(BlueprintType)
struct FCreateWidgetCommandData
{
	GENERATED_BODY()

	FCreateWidgetCommandData()
	{
		Owner = nullptr;
		bAddToViewport = true;
		bUIMode = true;
		bShowMouseCursor = true;
		ZOrder = 0;
		WidgetName = NAME_None;
	}

	/** Owner of widget. If not specified, then player 0 is owner*/
	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	APlayerController* Owner;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	TSubclassOf<UUserWidget> UserWidgetClass;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	bool bAddToViewport;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	bool bUIMode;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	bool bShowMouseCursor;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	int32 ZOrder;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	FName WidgetName;
};

/**
 * Command to create widget and add it to viewport
 */
UCLASS()
class COMMANDPACK_API UCreateWidgetCommand : public UBaseCommand
{
	GENERATED_BODY()


public:

	UFUNCTION(
		BlueprintCallable,
		BlueprintNativeEvent,
		Category = "Command Pack | Create Widget Command"
	)
	bool Init(
		UPARAM(DisplayName="WorldContextObject") UObject* InWorldContextObject,
		UPARAM(DisplayName="CommandData") FCreateWidgetCommandData InCommandData
	);

	UFUNCTION(
		BlueprintCallable,
		BlueprintNativeEvent,
		Category = "Command Pack | Create Widget Command"
	)
	UUserWidget* GetWidget(bool& bSuccess);

	virtual void Execute_Implementation() override;

protected:

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	FCreateWidgetCommandData CommandData;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	UUserWidget* Widget;
};
