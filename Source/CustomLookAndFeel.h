#pragma once
#include <JuceHeader.h>
class VelvetLookAndFeel : public juce::LookAndFeel_V4 {
public:
    VelvetLookAndFeel() {
        setColour(juce::Slider::thumbColourId,juce::Colour(0xff22d3a5));
        setColour(juce::Slider::rotarySliderFillColourId,juce::Colour(0xff22d3a5));
        setColour(juce::Slider::rotarySliderOutlineColourId,juce::Colour(0x3322d3a5));
        setColour(juce::Label::textColourId,juce::Colour(0xffe8eaf0));
        setColour(juce::ResizableWindow::backgroundColourId,juce::Colour(0xff0a1a14));
    }
    void drawRotarySlider(juce::Graphics& g,int x,int y,int w,int h,float pos,float sa,float ea,juce::Slider& sl) override {
        float r=juce::jmin(w*.5f,h*.5f)-4.f,cx=x+w*.5f,cy=y+h*.5f,angle=sa+pos*(ea-sa);
        juce::Path bg,fill;
        bg.addArc(cx-r,cy-r,r*2,r*2,sa,ea,true); g.setColour(sl.findColour(juce::Slider::rotarySliderOutlineColourId)); g.strokePath(bg,juce::PathStrokeType(3.5f,juce::PathStrokeType::curved,juce::PathStrokeType::rounded));
        fill.addArc(cx-r,cy-r,r*2,r*2,sa,angle,true); g.setColour(sl.findColour(juce::Slider::rotarySliderFillColourId)); g.strokePath(fill,juce::PathStrokeType(3.5f,juce::PathStrokeType::curved,juce::PathStrokeType::rounded));
        float tx=cx+(r-6)*std::cos(angle-juce::MathConstants<float>::halfPi),ty=cy+(r-6)*std::sin(angle-juce::MathConstants<float>::halfPi);
        g.setColour(sl.findColour(juce::Slider::thumbColourId)); g.fillEllipse(tx-3,ty-3,6,6);
    }
};
