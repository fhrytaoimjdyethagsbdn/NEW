#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PsyzumboAudioProcessorEditor::PsyzumboAudioProcessorEditor (PSY_ZUMBOAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (920, 560);
}

PsyzumboAudioProcessorEditor::~PsyzumboAudioProcessorEditor()
{
}

//==============================================================================
void PsyzumboAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colour::fromRGB (14, 18, 23));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (32.0f, juce::Font::bold));
    g.drawText ("PSY - ZUMBO", 28, 22, 430, 46, juce::Justification::left);

    g.setColour (juce::Colour::fromRGB (115, 255, 210));
    g.setFont (juce::FontOptions (13.0f));
    g.drawText ("DARK FOREST / PSY SYNTH - FOUNDATION BUILD", 31, 65, 520, 25, juce::Justification::left);

    g.setColour (juce::Colour::fromRGB (255, 110, 230));
    g.fillRoundedRectangle (24, 105, 872, 1, 1);

    g.setColour (juce::Colours::white.withAlpha (0.55f));
    g.setFont (juce::FontOptions (12.0f));
    g.drawText ("4-voice oscillation core • granular texture • filter • envelopes • LFO • presets", 31, 114, 600, 25, juce::Justification::left);
}

void PsyzumboAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any of your subcomponents..
    const int margin = 34;
    const int top = 135;
    const int w = 150;
    const int h = 125;

    // Add your layout code here if needed
}
