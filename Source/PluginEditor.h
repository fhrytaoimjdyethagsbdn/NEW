#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class PsyZumboAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    PsyZumboAudioProcessorEditor (PsyZumboAudioProcessor&);
    ~PsyZumboAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    PsyZumboAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PsyZumboAudioProcessorEditor)
};
