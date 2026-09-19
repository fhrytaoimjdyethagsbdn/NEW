#include "PluginProcessor.h"

//==============================================================================
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

//==============================================================================
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
    return 1;   // Απαιτείται τουλάχιστον 1 program για να είναι έγκυρο το plugin
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

//==============================================================================
void PsyZumboAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Αρχικοποίηση των DSP εφέ σου εδώ
}

void PsyZumboAudioProcessor::releaseResources()
{
    // Απελευθέρωση πόρων αν χρειάζεται
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

    // Καθαρισμός των καναλιών εξόδου που δεν έχουν δεδομένα εισόδου
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // Εδώ μπαίνει ο κώδικας επεξεργασίας ήχου (Audio Processing)
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        // Παράδειγμα: επεξεργασία των δειγμάτων ήχου στο channelData
    }
}

//==============================================================================
bool PsyZumboAudioProcessor::hasEditor() const
{
    return false; // Επιστρέφει false αν δεν υπάρχει custom GUI
}

juce::AudioProcessorEditor* PsyZumboAudioProcessor::createEditor()
{
    return nullptr; // Επιστρέφει nullptr επειδή το hasEditor είναι false
}

//==============================================================================
void PsyZumboAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // Αποθήκευση των παραμέτρων του plugin σου
}

void PsyZumboAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // Ανάκτηση των παραμέτρων του plugin σου
}

//==============================================================================
// Αυτό δημιουργεί το instance του plugin
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PsyZumboAudioProcessor();
}
