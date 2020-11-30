// Gradess & Novaturion Company. All rights reserved.


#include "QuitCommand.h"

#include "Kismet/KismetSystemLibrary.h"

bool UQuitCommand::Init_Implementation(
	UObject* InWorldContextObject,
	APlayerController* InSpecificPlayer,
	EQuitPreference::Type InQuitPreference,
	bool bInIgnorePlatformRestrictions
)
{
	const bool bResult = InitWorldContext(InWorldContextObject);
	
	PlayerController = InSpecificPlayer;
	QuitPreference = InQuitPreference;
	bIgnorePlatformRestrictions = bInIgnorePlatformRestrictions;
	return bResult;
}

void UQuitCommand::Execute_Implementation()
{
	UKismetSystemLibrary::QuitGame(
		WorldContextObject,
		PlayerController,
		QuitPreference,
		bIgnorePlatformRestrictions
	);
}
