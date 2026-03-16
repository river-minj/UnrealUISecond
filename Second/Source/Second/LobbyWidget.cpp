// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void ULobbyWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (BackButton && !BackButton->OnClicked.IsBound())
	{
		BackButton->OnClicked.AddDynamic(this, &ULobbyWidget::OnBackButtonClicked);
	}
}

void ULobbyWidget::OnBackButtonClicked()
{
	DeactivateWidget();
}
