#include "PluginProcessor.h"
#include "PluginEditor.h"

PsyZumboAudioProcessorEditor::PsyZumboAudioProcessorEditor (PsyZumboAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
}

PsyZumboAudioProcessorEditor::~PsyZumboAudioProcessorEditor()
{
}

void PsyZumboAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);

    // Χρήση standard πράσινου χρώματος που υποστηρίζεται παντού
    g.setColour (juce::Colours::green);
    g.setFont (15.0f);
    g.drawFittedText ("PSY - ZUMBO Synthesizer Core", getLocalBounds(), juce::Justification::centred, 1);
}

void PsyZumboAudioProcessorEditor::resized()
{
}



