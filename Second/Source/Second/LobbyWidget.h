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
class UWidgetSwitcher;
class UListView;
class UTileView;
class UCommonActivatableWidgetContainerBase;


UCLASS()
class SECOND_API ULobbyWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()
	

public:
	virtual void NativeConstruct() override;

protected:
	UFUNCTION()
	void OnShopButtonClicked();

	UFUNCTION()
	void OnInventoryButtonClicked();

	UFUNCTION()
	void OnSettingsButtonClicked();

	UFUNCTION()
	void OnBackButtonClicked();

    UPROPERTY(meta = (BindWidget))
    UButton* ShopButton;

    UPROPERTY(meta = (BindWidget))
    UButton* InventoryButton;

    UPROPERTY(meta = (BindWidget))
    UButton* SettingsButton;

    UPROPERTY(meta = (BindWidget))
    UButton* BackButton;

    UPROPERTY(meta = (BindWidget))
    UWidgetSwitcher* ContentSwitcher;

    UPROPERTY(meta = (BindWidget))
    UListView* ShopListView;

    UPROPERTY(meta = (BindWidget))
    UTileView* InventoryTileView;

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UCommonActivatableWidget> SettingsWidgetClass;

private:
    void PopulateShopItems();
    void PopulateInventoryItems();
    UCommonActivatableWidgetContainerBase* FindStackFromOuter() const;

};
