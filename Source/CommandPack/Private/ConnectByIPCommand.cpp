// Gradess & Novaturion Company. All rights reserved.


#include "ConnectByIPCommand.h"
#include "Kismet/KismetSystemLibrary.h"

bool UConnectByIPCommand::Init_Implementation(
	UObject* InWorldContextObject,
	FConnectByIPCommandData InCommandData
)
{
	const auto bResult = InitWorldContext(InWorldContextObject);

	CommandData = InCommandData;

	return bResult;
}

void UConnectByIPCommand::Execute_Implementation()
{
	const auto Command = FString(TEXT("open ")).Append(CommandData.IP);
	UKismetSystemLibrary::ExecuteConsoleCommand(WorldContextObject, Command, CommandData.PlayerController);
}
