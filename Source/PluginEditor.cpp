#include "PluginEditor.h"
VelvetAudioProcessorEditor::VelvetAudioProcessorEditor(VelvetAudioProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p),
      att_DELAY_DELAY_MS_BCCO(*processorRef.apvts.getParameter("DELAY_DELAY_MS_BCCO"),knob_DELAY_DELAY_MS_BCCO),
      att_DELAY_FEEDBACK_BCCO(*processorRef.apvts.getParameter("DELAY_FEEDBACK_BCCO"),knob_DELAY_FEEDBACK_BCCO),
      att_DELAY_MIX_BCCO(*processorRef.apvts.getParameter("DELAY_MIX_BCCO"),knob_DELAY_MIX_BCCO),
      att_GAIN_GAIN_DB_YPYX(*processorRef.apvts.getParameter("GAIN_GAIN_DB_YPYX"),knob_GAIN_GAIN_DB_YPYX),
      att_DISTORTION_DRIVE_UJ80(*processorRef.apvts.getParameter("DISTORTION_DRIVE_UJ80"),knob_DISTORTION_DRIVE_UJ80),
      att_DISTORTION_MIX_UJ80(*processorRef.apvts.getParameter("DISTORTION_MIX_UJ80"),knob_DISTORTION_MIX_UJ80)
{
    setLookAndFeel(&lnf); setSize(480,270);
    knob_DELAY_DELAY_MS_BCCO.setSliderStyle(juce::Slider::Rotary); knob_DELAY_DELAY_MS_BCCO.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_DELAY_DELAY_MS_BCCO.setLookAndFeel(&lnf); addAndMakeVisible(knob_DELAY_DELAY_MS_BCCO); lbl_DELAY_DELAY_MS_BCCO.setText("Delay Time",juce::dontSendNotification); lbl_DELAY_DELAY_MS_BCCO.setJustificationType(juce::Justification::centred); lbl_DELAY_DELAY_MS_BCCO.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_DELAY_DELAY_MS_BCCO);
    knob_DELAY_FEEDBACK_BCCO.setSliderStyle(juce::Slider::Rotary); knob_DELAY_FEEDBACK_BCCO.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_DELAY_FEEDBACK_BCCO.setLookAndFeel(&lnf); addAndMakeVisible(knob_DELAY_FEEDBACK_BCCO); lbl_DELAY_FEEDBACK_BCCO.setText("Delay Feedback",juce::dontSendNotification); lbl_DELAY_FEEDBACK_BCCO.setJustificationType(juce::Justification::centred); lbl_DELAY_FEEDBACK_BCCO.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_DELAY_FEEDBACK_BCCO);
    knob_DELAY_MIX_BCCO.setSliderStyle(juce::Slider::Rotary); knob_DELAY_MIX_BCCO.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_DELAY_MIX_BCCO.setLookAndFeel(&lnf); addAndMakeVisible(knob_DELAY_MIX_BCCO); lbl_DELAY_MIX_BCCO.setText("Delay Mix",juce::dontSendNotification); lbl_DELAY_MIX_BCCO.setJustificationType(juce::Justification::centred); lbl_DELAY_MIX_BCCO.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_DELAY_MIX_BCCO);
    knob_GAIN_GAIN_DB_YPYX.setSliderStyle(juce::Slider::Rotary); knob_GAIN_GAIN_DB_YPYX.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_GAIN_GAIN_DB_YPYX.setLookAndFeel(&lnf); addAndMakeVisible(knob_GAIN_GAIN_DB_YPYX); lbl_GAIN_GAIN_DB_YPYX.setText("Gain Gain",juce::dontSendNotification); lbl_GAIN_GAIN_DB_YPYX.setJustificationType(juce::Justification::centred); lbl_GAIN_GAIN_DB_YPYX.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_GAIN_GAIN_DB_YPYX);
    knob_DISTORTION_DRIVE_UJ80.setSliderStyle(juce::Slider::Rotary); knob_DISTORTION_DRIVE_UJ80.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_DISTORTION_DRIVE_UJ80.setLookAndFeel(&lnf); addAndMakeVisible(knob_DISTORTION_DRIVE_UJ80); lbl_DISTORTION_DRIVE_UJ80.setText("Distortion Drive",juce::dontSendNotification); lbl_DISTORTION_DRIVE_UJ80.setJustificationType(juce::Justification::centred); lbl_DISTORTION_DRIVE_UJ80.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_DISTORTION_DRIVE_UJ80);
    knob_DISTORTION_MIX_UJ80.setSliderStyle(juce::Slider::Rotary); knob_DISTORTION_MIX_UJ80.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16); knob_DISTORTION_MIX_UJ80.setLookAndFeel(&lnf); addAndMakeVisible(knob_DISTORTION_MIX_UJ80); lbl_DISTORTION_MIX_UJ80.setText("Distortion Mix",juce::dontSendNotification); lbl_DISTORTION_MIX_UJ80.setJustificationType(juce::Justification::centred); lbl_DISTORTION_MIX_UJ80.setFont(juce::Font(9.5f,juce::Font::bold)); addAndMakeVisible(lbl_DISTORTION_MIX_UJ80);
}
VelvetAudioProcessorEditor::~VelvetAudioProcessorEditor() { setLookAndFeel(nullptr); }
void VelvetAudioProcessorEditor::paint(juce::Graphics& g) {
    g.fillAll(juce::Colour(0xff0a1a14));
    g.setColour(juce::Colour(0xff22d3a5).withAlpha(0.1f)); g.fillRect(0,0,getWidth(),50);
    g.setColour(juce::Colour(0xffe8eaf0).withAlpha(0.45f)); g.setFont(juce::Font("Inter",10.f,juce::Font::bold));
    g.drawText("ARCHERGATE",16,6,getWidth()-32,14,juce::Justification::left);
    g.setColour(juce::Colour(0xff22d3a5)); g.setFont(juce::Font("Inter",15.f,juce::Font::bold));
    g.drawText("VELVET",16,20,getWidth()-32,18,juce::Justification::centred);
}
void VelvetAudioProcessorEditor::resized() {
    knob_DELAY_DELAY_MS_BCCO.setBounds(20+0*110,60+0*90,85,70); lbl_DELAY_DELAY_MS_BCCO.setBounds(20+0*110,127+0*90,85,13);
    knob_DELAY_FEEDBACK_BCCO.setBounds(20+1*110,60+0*90,85,70); lbl_DELAY_FEEDBACK_BCCO.setBounds(20+1*110,127+0*90,85,13);
    knob_DELAY_MIX_BCCO.setBounds(20+2*110,60+0*90,85,70); lbl_DELAY_MIX_BCCO.setBounds(20+2*110,127+0*90,85,13);
    knob_GAIN_GAIN_DB_YPYX.setBounds(20+3*110,60+0*90,85,70); lbl_GAIN_GAIN_DB_YPYX.setBounds(20+3*110,127+0*90,85,13);
    knob_DISTORTION_DRIVE_UJ80.setBounds(20+0*110,60+1*90,85,70); lbl_DISTORTION_DRIVE_UJ80.setBounds(20+0*110,127+1*90,85,13);
    knob_DISTORTION_MIX_UJ80.setBounds(20+1*110,60+1*90,85,70); lbl_DISTORTION_MIX_UJ80.setBounds(20+1*110,127+1*90,85,13);
}
