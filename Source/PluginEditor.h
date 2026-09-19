#pragma once

// Απευθείας include των γραφικών modules της JUCE
#include <juce_gui_basics/juce_gui_basics.h>
#include "PluginProcessor.h"

class PsyZumboAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    PsyZumboAudioProcessorEditor (PsyZumboAudioProcessor&);
    ~PsyZumboAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    PsyZumboAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PsyZumboAudioProcessorEditor)
};


