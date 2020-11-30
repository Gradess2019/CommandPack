// Gradess & Novaturion Company. All rights reserved.


#include "CreateWidgetCommand.h"


#include "SetInputModeCommand.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

bool UCreateWidgetCommand::Init_Implementation(
	UObject* InWorldContextObject,
	FCreateWidgetCommandData InCommandData
)
{
	const auto bResult = InitWorldContext(InWorldContextObject);

	if (!IsValid(InCommandData.Owner))
	{
		InCommandData.Owner = UGameplayStatics::GetPlayerController(InWorldContextObject, 0);
	}

	CommandData = InCommandData;

	return bResult;
}

UUserWidget* UCreateWidgetCommand::GetWidget_Implementation(bool& bSuccess)
{
	bSuccess = IsValid(Widget);
	return Widget;
}

void UCreateWidgetCommand::Execute_Implementation()
{
	if (!IsValid(CommandData.UserWidgetClass)) { return; }

	Widget = CreateWidget(CommandData.Owner, CommandData.UserWidgetClass, CommandData.WidgetName);
	if (!IsValid(Widget)) { return; }

	if (CommandData.bAddToViewport)
	{
		Widget->AddToViewport(CommandData.ZOrder);
	}
	
	if (CommandData.bUIMode)
	{
		auto SetInputModeCommand = NewObject<USetInputModeCommand>(this, USetInputModeCommand::StaticClass());
		const auto InputCommandData = FSetInputModeCommandData(this->CommandData.Owner, EInputMode::UI, Widget);
		SetInputModeCommand->Init(WorldContextObject, InputCommandData);
		SetInputModeCommand->Execute();
	}
	
	CommandData.Owner->bShowMouseCursor = CommandData.bShowMouseCursor;
}
