// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "LobbyWidget.generated.h"

/**
 * 
 */

class UButton;
class UTextBlock;

UCLASS()
class SECOND_API ULobbyWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()
	

public:
	virtual void NativeConstruct() override;

protected:
	UFUNCTION()
		void OnBackButtonClicked();

	UPROPERTY(meta = (BindWidget))
	UButton* BackButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* LobbyText;


};
