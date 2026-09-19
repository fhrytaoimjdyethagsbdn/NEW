#include "PluginProcessor.h"
#include "PluginEditor.h"

PsyZumboAudioProcessor::PsyZumboAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

PsyZumboAudioProcessor::~PsyZumboAudioProcessor()
{
}

const juce::String PsyZumboAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PsyZumboAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PsyZumboAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PsyZumboAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double PsyZumboAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PsyZumboAudioProcessor::getNumPrograms()
{
    return 1;
}

int PsyZumboAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PsyZumboAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String PsyZumboAudioProcessor::getProgramName (int index)
{
    return {};
}

void PsyZumboAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

void PsyZumboAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused (sampleRate, samplesPerBlock);
}

void PsyZumboAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PsyZumboAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutput() != juce::AudioChannelSet::mono()
     && layouts.getMainOutput() != juce::AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutput() != layouts.getMainInput())
        return false;
   #endif

    return true;
  #endif
}
#endif

void PsyZumboAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        juce::ignoreUnused (channelData);
    }
}

bool PsyZumboAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* PsyZumboAudioProcessor::createEditor()
{
    return new PsyZumboAudioProcessorEditor (*this);
}

void PsyZumboAudioProcessorProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    juce::ignoreUnused (destData);
}

void PsyZumboAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    juce::ignoreUnused (data, sizeInBytes);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PsyZumboAudioProcessor();
}


