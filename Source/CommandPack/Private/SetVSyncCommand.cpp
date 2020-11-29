// Gradess & Novaturion Company. All rights reserved.


#include "SetVSyncCommand.h"
#include "GameFramework/GameUserSettings.h"

bool USetVSyncCommand::Init_Implementation(
	UObject* InWorldContextObject,
	bool bInEnable,
	bool bInCheckCommandLineOverrides
)
{
	const auto bResult = InitWorldContext(InWorldContextObject);

	bEnable = bInEnable;
	bCheckCommandLineOverrides = bInCheckCommandLineOverrides;

	return bResult;
}

void USetVSyncCommand::Execute_Implementation()
{
	auto GameUserSettings = UGameUserSettings::GetGameUserSettings();
	GameUserSettings->SetVSyncEnabled(bEnable);
	GameUserSettings->ApplySettings(bCheckCommandLineOverrides);
}
