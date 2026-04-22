#include "SettingsWidget.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"
#include "Components/CheckBox.h"
#include "Components/ComboBoxString.h"
#include "Components/Button.h"

void USettingsWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (BGMSlider && !BGMSlider->OnValueChanged.IsBound())
    {
        BGMSlider->SetValue(0.5f);
        BGMSlider->OnValueChanged.AddDynamic(this, &USettingsWidget::OnBGMVolumeChanged);
        OnBGMVolumeChanged(0.5f);
    }

    if (SFXSlider && !SFXSlider->OnValueChanged.IsBound())
    {
        SFXSlider->SetValue(0.5f);
        SFXSlider->OnValueChanged.AddDynamic(this, &USettingsWidget::OnSFXVolumeChanged);
        OnSFXVolumeChanged(0.5f);
    }

    if (FullscreenCheckBox && !FullscreenCheckBox->OnCheckStateChanged.IsBound())
    {
        FullscreenCheckBox->OnCheckStateChanged.AddDynamic(this, &USettingsWidget::OnFullscreenChanged);
    }

    if (LanguageComboBox && !LanguageComboBox->OnSelectionChanged.IsBound())
    {
        LanguageComboBox->AddOption(TEXT("한국어"));
        LanguageComboBox->AddOption(TEXT("English"));
        LanguageComboBox->SetSelectedIndex(0);
        LanguageComboBox->OnSelectionChanged.AddDynamic(this, &USettingsWidget::OnLanguageChanged);
    }

    if (BackButton && !BackButton->OnClicked.IsBound())
    {
        BackButton->OnClicked.AddDynamic(this, &USettingsWidget::OnBackButtonClicked);
    }
}

void USettingsWidget::OnBGMVolumeChanged(float Value)
{
    int32 DisplayValue = FMath::RoundToInt(Value * 100.f);
    BGMValueText->SetText(FText::FromString(FString::Printf(TEXT("%d"), DisplayValue)));
    UE_LOG(LogTemp, Log, TEXT("BGM Volume: %d"), DisplayValue);
}

void USettingsWidget::OnSFXVolumeChanged(float Value)
{
    int32 DisplayValue = FMath::RoundToInt(Value * 100.f);
    SFXValueText->SetText(FText::FromString(FString::Printf(TEXT("%d"), DisplayValue)));
    UE_LOG(LogTemp, Log, TEXT("SFX Volume: %d"), DisplayValue);
}

void USettingsWidget::OnFullscreenChanged(bool bIsChecked)
{
    UE_LOG(LogTemp, Log, TEXT("Fullscreen: %s"), bIsChecked ? TEXT("ON") : TEXT("OFF"));
}

void USettingsWidget::OnLanguageChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
    UE_LOG(LogTemp, Log, TEXT("Language: %s"), *SelectedItem);
}

void USettingsWidget::OnBackButtonClicked()
{
    DeactivateWidget();
}

bool USettingsWidget::NativeOnHandleBackAction()
{
    DeactivateWidget();
    return true;
}