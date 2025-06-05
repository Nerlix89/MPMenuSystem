// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"

#include "MPMenu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMPMenu : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void MPMenuSetup();

	UFUNCTION(BlueprintCallable)
	void ClickedOnHostButton(int32 ChosenNumberPublicConnections = 4, FString ChosenMatchType = "FreeForAll", FString LobbyPath = FString(TEXT("/Game/ThirdPerson/Maps/Map_Lobby")));
	UFUNCTION(BlueprintCallable)
	void ClickedOnJoinButton();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void EnableHostAndJoinButtons(bool bEnable);

protected:

	virtual void NativeDestruct() override;

	//
	// Callbacks for the custom delegates on the MultiplayerSessionSubsystem
	//
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
	void OnFindSessions(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);
	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);

private:

	// The subsystem designed to handle all online session functionality
	class UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;

	void MenuTearDown();

	FString MatchType{TEXT("FreeForAll") };
	FString PathToLobby{ TEXT("") };

};
