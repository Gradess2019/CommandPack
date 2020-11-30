// Gradess & Novaturion Company. All rights reserved.


#include "SetInputModeCommand.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"

bool USetInputModeCommand::Init_Implementation(UObject* InWorldContextObject, FSetInputModeCommandData InCommandData)
{
	const auto bResult = InitWorldContext(InWorldContextObject);

	if (IsValid(InCommandData.PlayerController))
	{
		InCommandData.PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	}

	CommandData = InCommandData;

	return bResult;
}

void USetInputModeCommand::Execute_Implementation()
{
	switch (CommandData.InputMode)
	{
	case EInputMode::GameAndUI:
		{
			SetInputModeGameAndUI();
			break;
		}

	case EInputMode::UI:
		{
			SetInputModeUIOnly();
			break;
		}

	case EInputMode::Game:
		{
			SetInputModeGameOnly();
			break;
		}
	}
}

void USetInputModeCommand::SetInputModeGameAndUI() const
{
	UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(
		CommandData.PlayerController,
		CommandData.WidgetToFocus,
		CommandData.MouseLockMode,
		CommandData.bHideCursorDuringCapture
	);
}

void USetInputModeCommand::SetInputModeUIOnly() const
{
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(
		CommandData.PlayerController,
		CommandData.WidgetToFocus,
		CommandData.MouseLockMode
	);
}

void USetInputModeCommand::SetInputModeGameOnly() const
{
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(
		CommandData.PlayerController
	);
}
