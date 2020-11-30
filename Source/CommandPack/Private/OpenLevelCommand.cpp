// Gradess & Novaturion Company. All rights reserved.


#include "OpenLevelCommand.h"
#include "Kismet/GameplayStatics.h"

bool UOpenLevelCommand::Init_Implementation(
	UObject* InWorldContextObject,
	FName InLevelName,
	bool bInAbsolute,
	const FString& InOptions
)
{
	const bool bResult = InitWorldContext(InWorldContextObject);

	LevelName = InLevelName;
	bAbsolute = bInAbsolute;
	Options = InOptions;

	return bResult;
}

void UOpenLevelCommand::Execute_Implementation()
{
	UGameplayStatics::OpenLevel(WorldContextObject, LevelName, bAbsolute, Options);
}
