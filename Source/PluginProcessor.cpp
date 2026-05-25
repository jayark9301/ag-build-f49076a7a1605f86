#include "PluginProcessor.h"
#include "PluginEditor.h"
VelvetAudioProcessor::VelvetAudioProcessor()
    : AudioProcessor(BusesProperties().withInput("Input",juce::AudioChannelSet::stereo()).withOutput("Output",juce::AudioChannelSet::stereo())),
      apvts(*this,nullptr,"Parameters",createParameterLayout()) {}
VelvetAudioProcessor::~VelvetAudioProcessor() {}
juce::AudioProcessorValueTreeState::ParameterLayout VelvetAudioProcessor::createParameterLayout() {
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    layout.add(std::make_unique<juce::AudioParameterFloat>("DELAY_DELAY_MS_BCCO","Delay Time",juce::NormalisableRange<float>(1f,2000f,0.01f),250f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DELAY_FEEDBACK_BCCO","Delay Feedback",juce::NormalisableRange<float>(0f,95f,0.01f),40f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DELAY_MIX_BCCO","Delay Mix",juce::NormalisableRange<float>(0f,100f,0.01f),30f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("GAIN_GAIN_DB_YPYX","Gain Gain",juce::NormalisableRange<float>(-24f,24f,0.01f),0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DISTORTION_DRIVE_UJ80","Distortion Drive",juce::NormalisableRange<float>(0f,100f,0.01f),30f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DISTORTION_MIX_UJ80","Distortion Mix",juce::NormalisableRange<float>(0f,100f,0.01f),60f));
    return layout;
}
void VelvetAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    juce::dsp::ProcessSpec spec;
    spec.sampleRate=(uint32_t)sampleRate; spec.maximumBlockSize=(uint32_t)samplesPerBlock; spec.numChannels=(uint32_t)getTotalNumOutputChannels();
    delay_BCCO.prepare(spec); delay_BCCO.setMaximumDelayInSamples((int)(spec.sampleRate*2.0)); delayMix_BCCO.prepare(spec); delayMix_BCCO.setWetMixProportion(0.3f);
    gain_YPYX.prepare(spec); gain_YPYX.setGainDecibels(0f);
    dist_UJ80.functionToUse=[](float x){return std::tanh(x*4f);}; dist_UJ80.prepare(spec); distMix_UJ80.prepare(spec); distMix_UJ80.setWetMixProportion(0.6f);
}
void VelvetAudioProcessor::releaseResources() {}
bool VelvetAudioProcessor::isBusesLayoutSupported(const BusesLayout& l) const {
    return l.getMainOutputChannelSet()==juce::AudioChannelSet::stereo()&&l.getMainInputChannelSet()==juce::AudioChannelSet::stereo();
}
void VelvetAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) {
    juce::ScopedNoDenormals noDenormals;
    juce::dsp::AudioBlock<float> block(buffer);
    juce::dsp::ProcessContextReplacing<float> context(block);
    { delayMix_BCCO.pushDrySamples(block); delay_BCCO.process(context); delayMix_BCCO.mixWetSamples(block); }
    gain_YPYX.process(context);
    { distMix_UJ80.pushDrySamples(block); dist_UJ80.process(context); distMix_UJ80.mixWetSamples(block); }
}
void VelvetAudioProcessor::getStateInformation(juce::MemoryBlock& d) {
    auto s=apvts.copyState(); std::unique_ptr<juce::XmlElement> xml(s.createXml()); copyXmlToBinary(*xml,d);
}
void VelvetAudioProcessor::setStateInformation(const void* d,int sz) {
    std::unique_ptr<juce::XmlElement> xml(getXmlFromBinary(d,sz));
    if(xml&&xml->hasTagName(apvts.state.getType())) apvts.replaceState(juce::ValueTree::fromXml(*xml));
}
juce::AudioProcessorEditor* VelvetAudioProcessor::createEditor() { return new VelvetAudioProcessorEditor(*this); }
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() { return new VelvetAudioProcessor(); }
