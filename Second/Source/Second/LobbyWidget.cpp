// Fill out your copyright notice in the Description page of Project Settings.

#include "LobbyWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "Components/ListView.h"
#include "Components/TileView.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "MainHUDWidget.h"
#include "ShopItemData.h"
#include "InventoryItemData.h"

void ULobbyWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (ShopButton && !ShopButton->OnClicked.IsBound())
    {
        ShopButton->OnClicked.AddDynamic(this, &ULobbyWidget::OnShopButtonClicked);
    }
    if (InventoryButton && !InventoryButton->OnClicked.IsBound())
    {
        InventoryButton->OnClicked.AddDynamic(this, &ULobbyWidget::OnInventoryButtonClicked);
    }
    if (SettingsButton && !SettingsButton->OnClicked.IsBound())
    {
        SettingsButton->OnClicked.AddDynamic(this, &ULobbyWidget::OnSettingsButtonClicked);
    }
    if (BackButton && !BackButton->OnClicked.IsBound())
    {
        BackButton->OnClicked.AddDynamic(this, &ULobbyWidget::OnBackButtonClicked);
    }

    //상점 및 인벤토리 데이터 초기화
    PopulateShopItems();
    PopulateInventoryItems();
}

void ULobbyWidget::OnShopButtonClicked()
{
    ContentSwitcher->SetActiveWidgetIndex(0);
}

void ULobbyWidget::OnInventoryButtonClicked()
{
    ContentSwitcher->SetActiveWidgetIndex(1);
}

void ULobbyWidget::OnSettingsButtonClicked()
{
    // 설정은 스택에 Push (탭이 아닌 별도 화면)
    UCommonActivatableWidgetContainerBase* Stack = FindStackFromOuter();
    if (Stack && SettingsWidgetClass)
    {
        Stack->AddWidget(SettingsWidgetClass);
    }
}
void ULobbyWidget::OnBackButtonClicked()
{
	DeactivateWidget();
}

void ULobbyWidget::PopulateShopItems()
{
    if (!ShopListView) return;

    struct {
        const TCHAR* Name; int32 Price;
    } Items[] = {
        { TEXT("장검"), 1000 },
        { TEXT("단검"), 500 },
        { TEXT("방패"), 800 },
        { TEXT("물약"), 100 }
    };

    for (auto& Item : Items)
    {
        UShopItemData* Data = NewObject<UShopItemData>(this);
        Data->Init(Item.Name, Item.Price);
        ShopListView->AddItem(Data);
    }
}

void ULobbyWidget::PopulateInventoryItems()
{
	if (!InventoryTileView) return;

	struct {
		const TCHAR* Name; int32 Qty;
	} Items[] = {
        { TEXT("장검"), 1 },
        { TEXT("단검"), 3 },
        { TEXT("방패"), 1 },
        { TEXT("물약"), 10 }
	};

    for (auto& Item : Items)
    {
        UInventoryItemData* Data = NewObject<UInventoryItemData>(this);
        Data->Init(Item.Name, Item.Qty);
        InventoryTileView->AddItem(Data);
    }
}

UCommonActivatableWidgetContainerBase* ULobbyWidget::FindStackFromOuter() const
{
    UObject* Current = GetOuter();
    while (Current)
    {
        UMainHUDWidget* HUD = Cast<UMainHUDWidget>(Current);
        if (HUD)
        {
            return HUD->GetMainStack();
        }
        Current = Current->GetOuter();
    }
    return nullptr;
}

bool ULobbyWidget::NativeOnHandleBackAction()
{
    DeactivateWidget();

	return true;
}