#pragma once
#include "PluginProcessor.h"
#include "CustomLookAndFeel.h"
class VelvetAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
    VelvetAudioProcessorEditor(VelvetAudioProcessor&);
    ~VelvetAudioProcessorEditor() override;
    void paint(juce::Graphics&) override;
    void resized() override;
private:
    VelvetAudioProcessor& processorRef;
    VelvetLookAndFeel lnf;
    juce::Slider knob_DELAY_DELAY_MS_BCCO;
    juce::Label lbl_DELAY_DELAY_MS_BCCO;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DELAY_DELAY_MS_BCCO;
    juce::Slider knob_DELAY_FEEDBACK_BCCO;
    juce::Label lbl_DELAY_FEEDBACK_BCCO;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DELAY_FEEDBACK_BCCO;
    juce::Slider knob_DELAY_MIX_BCCO;
    juce::Label lbl_DELAY_MIX_BCCO;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DELAY_MIX_BCCO;
    juce::Slider knob_GAIN_GAIN_DB_YPYX;
    juce::Label lbl_GAIN_GAIN_DB_YPYX;
    juce::AudioProcessorValueTreeState::SliderAttachment att_GAIN_GAIN_DB_YPYX;
    juce::Slider knob_DISTORTION_DRIVE_UJ80;
    juce::Label lbl_DISTORTION_DRIVE_UJ80;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DISTORTION_DRIVE_UJ80;
    juce::Slider knob_DISTORTION_MIX_UJ80;
    juce::Label lbl_DISTORTION_MIX_UJ80;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DISTORTION_MIX_UJ80;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VelvetAudioProcessorEditor)
};
