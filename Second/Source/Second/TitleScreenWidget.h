// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "TitleScreenWidget.generated.h"

/**
 * 
 */

class UButton;
class UTextBlock;
class UCommonActivatableWidgetContainerBase;

UCLASS()
class SECOND_API UTitleScreenWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;


protected:

	UFUNCTION()
	void OnStartButtonClicked();

	UPROPERTY(meta = (BindWidget))
	UButton* StartButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TitleText;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UCommonActivatableWidget> LobbyWidgetClass;

private:

	UCommonActivatableWidgetContainerBase* FindStackFromOuter() const;
};
