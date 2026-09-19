#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PsyZumboAudioProcessorEditor::PsyZumboAudioProcessorEditor (PsyZumboAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Ορισμός του μεγέθους του παραθύρου του plugin
    setSize (400, 300);
}

PsyZumboAudioProcessorEditor::~PsyZumboAudioProcessorEditor()
{
}

//==============================================================================
void PsyZumboAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Σχεδίαση απλού background για να μην είναι κενό
    g.fillAll (juce::Colours::black);

    g.setColour (juce::Colours::neonGreen);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("PSY - ZUMBO Synthesizer Core", getLocalBounds(), juce::Justification::centred, 1);
}

void PsyZumboAudioProcessorEditor::resized()
{
    // Εδώ μπαίνει η τοποθέτηση των UI στοιχείων (sliders, κουμπιά) στο μέλλον
}
