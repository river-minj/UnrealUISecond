#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "ShopItemEntry.generated.h"

class UTextBlock;

UCLASS()
class SECOND_API UShopItemEntry : public UUserWidget, public IUserObjectListEntry
{
    GENERATED_BODY()
public:
    virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

protected:
    UPROPERTY(meta = (BindWidget))
    UTextBlock* ItemNameText;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* ItemPriceText;
};