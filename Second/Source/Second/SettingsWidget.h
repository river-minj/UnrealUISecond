#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "SettingsWidget.generated.h"

class USlider;
class UTextBlock;
class UCheckBox;
class UComboBoxString;
class UButton;

UCLASS()
class SECOND_API USettingsWidget : public UCommonActivatableWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

protected:
    UFUNCTION()
    void OnBGMVolumeChanged(float Value);

    UFUNCTION()
    void OnSFXVolumeChanged(float Value);

    UFUNCTION()
    void OnFullscreenChanged(bool bIsChecked);

    UFUNCTION()
    void OnLanguageChanged(FString SelectedItem, ESelectInfo::Type SelectionType);

    UFUNCTION()
    void OnBackButtonClicked();

    virtual bool NativeOnHandleBackAction() override;

    UPROPERTY(meta = (BindWidget))
    USlider* BGMSlider;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* BGMValueText;

    UPROPERTY(meta = (BindWidget))
    USlider* SFXSlider;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* SFXValueText;

    UPROPERTY(meta = (BindWidget))
    UCheckBox* FullscreenCheckBox;

    UPROPERTY(meta = (BindWidget))
    UComboBoxString* LanguageComboBox;

    UPROPERTY(meta = (BindWidget))
    UButton* BackButton;
};