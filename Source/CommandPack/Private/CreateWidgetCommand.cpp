// Gradess & Novaturion Company. All rights reserved.


#include "CreateWidgetCommand.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

bool UCreateWidgetCommand::Init_Implementation(
	UObject* InWorldContextObject,
	APlayerController* InOwner,
	TSubclassOf<UUserWidget> InUserWidgetClass,
	FName InWidgetName,
	bool bInAddToViewport,
	int32 InZOrder
)
{
	const auto bResult = InitWorldContext(InWorldContextObject);

	if (!IsValid(InOwner))
	{
		InOwner = UGameplayStatics::GetPlayerController(InWorldContextObject, 0);
	}

	Owner = InOwner;
	UserWidgetClass = InUserWidgetClass;
	WidgetName = InWidgetName;
	bAddToViewport = bInAddToViewport;

	return bResult;
}

UUserWidget* UCreateWidgetCommand::GetWidget_Implementation(bool& bSuccess)
{
	bSuccess = IsValid(Widget);
	return Widget;
}

void UCreateWidgetCommand::Execute_Implementation()
{
	Widget = CreateWidget(Owner, UserWidgetClass, WidgetName);
	if (!(IsValid(Widget) && bAddToViewport)) { return; }

	Widget->AddToViewport(ZOrder);
}
