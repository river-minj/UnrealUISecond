#include "InventoryItemEntry.h"
#include "Components/TextBlock.h"
#include "InventoryItemData.h"

void UInventoryItemEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
    UInventoryItemData* Data = Cast<UInventoryItemData>(ListItemObject);
    if (Data)
    {
        ItemNameText->SetText(FText::FromString(Data->ItemName));
        ItemQuantityText->SetText(FText::FromString(FString::Printf(TEXT("x%d"), Data->Quantity)));
    }
}
