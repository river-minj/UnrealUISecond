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
    // GetParent() 체인
    UE_LOG(LogTemp, Warning, TEXT("=== GetParent() 체인 ==="));
    UWidget* Parent = GetParent();
    if (Parent)
    {
        UE_LOG(LogTemp, Warning, TEXT("Parent: %s (%s)"), *Parent->GetName(), *Parent->GetClass()->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Parent: nullptr (없음!)"));
    }

    // GetOuter() 체인
    UE_LOG(LogTemp, Warning, TEXT("=== GetOuter() 체인 ==="));
    UObject* Current = GetOuter();
    while (Current)
    {
        UE_LOG(LogTemp, Warning, TEXT("Outer: %s (%s)"), *Current->GetName(), *Current->GetClass()->GetName());
        Current = Current->GetOuter();
    }
}
//void UTitleScreenWidget::OnStartButtonClicked()
//{
//	UCommonActivatableWidgetContainerBase* Stack = FindStackFromOuter();
//
//	if (Stack && LobbyWidgetClass)
//	{
//		Stack->AddWidget(LobbyWidgetClass);
//	}
//}

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