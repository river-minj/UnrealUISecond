// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUDWidget.h"
#include "Widgets/CommonActivatableWidgetContainer.h"

void UMainHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (MainStack && InitialWidgetClass)
	{
		MainStack->AddWidget(InitialWidgetClass);
	}
}
