// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleScreenWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "MainHUDWidget.h"


void UTitleScreenWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (StartButton && !StartButton->OnClicked.IsBound())
	{
		StartButton->OnClicked.AddDynamic(this, &UTitleScreenWidget::OnStartButtonClicked);
	}

}

void UTitleScreenWidget::OnStartButtonClicked()
{
    UCommonActivatableWidgetContainerBase* Stack = FindStackFromOuter();

    if (Stack && LobbyWidgetClass)
    {
        Stack->AddWidget(LobbyWidgetClass);
    }
}

UCommonActivatableWidgetContainerBase* UTitleScreenWidget::FindStackFromOuter() const
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