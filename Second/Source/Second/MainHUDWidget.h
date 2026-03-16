// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "MainHUDWidget.generated.h"

/**
 * 
 */
class UCommonActivatableWidgetStack;

UCLASS()
class SECOND_API UMainHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	//외부에서 스택에 접근할 수 있도록 Getter제공
	UCommonActivatableWidgetStack* GetMainStack() const {
		return MainStack;
	}

protected:
	UPROPERTY(meta= (BindWidget))
	UCommonActivatableWidgetStack* MainStack;

	//처음에 스택에 Push할 위젯 클래스 (타이틀 화면)
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UCommonActivatableWidget> InitialWidgetClass;
};
