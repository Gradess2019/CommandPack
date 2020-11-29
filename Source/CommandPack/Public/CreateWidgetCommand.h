// Gradess & Novaturion Company. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseCommand.h"
#include "CreateWidgetCommand.generated.h"

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
		Category = "Command Pack | Create Widget Command",
		meta=(AdvancedDisplay=3)
	)
	bool Init(
		UPARAM(DisplayName="WorldContextObject") UObject* InWorldContextObject,
		UPARAM(DisplayName="Owner") APlayerController* InOwner,
		UPARAM(DisplayName="Class") TSubclassOf<UUserWidget> InUserWidgetClass,
		UPARAM(DisplayName="Name") FName InWidgetName = NAME_None,
		UPARAM(DisplayName="AddToViewport") bool bInAddToViewport = true,
		UPARAM(DisplayName="ZOrder") int32 InZOrder = 0
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
	APlayerController* Owner;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	TSubclassOf<UUserWidget> UserWidgetClass;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	FName WidgetName;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	bool bAddToViewport;
	
	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	int32 ZOrder;

	UPROPERTY(BlueprintReadWrite, Category = "Command Pack | Create Widget Command")
	UUserWidget* Widget;
};
