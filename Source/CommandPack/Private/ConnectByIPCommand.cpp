// Gradess & Novaturion Company. All rights reserved.


#include "ConnectByIPCommand.h"

#include "Kismet/KismetSystemLibrary.h"

bool UConnectByIPCommand::Init_Implementation(
	UObject* InWorldContextObject,
	const FString& InIP,
	APlayerController* InPlayerController
)
{
	const auto bResult = InitWorldContext(InWorldContextObject);

	IP = InIP;
	PlayerController = InPlayerController;

	return bResult;
}

void UConnectByIPCommand::Execute_Implementation()
{
	const auto Command = FString(TEXT("open ")).Append(IP);
	UKismetSystemLibrary::ExecuteConsoleCommand(WorldContextObject, Command, PlayerController);
}
