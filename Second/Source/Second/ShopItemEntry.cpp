#include "ShopItemEntry.h"
#include "Components/TextBlock.h"
#include "ShopItemData.h"

void UShopItemEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
    UShopItemData* Data = Cast<UShopItemData>(ListItemObject);
    if (Data)
    {
        ItemNameText->SetText(FText::FromString(Data->ItemName));
        ItemPriceText->SetText(FText::FromString(FString::Printf(TEXT("%d G"), Data->Price)));
    }
}