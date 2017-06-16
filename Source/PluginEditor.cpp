/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SampleBrowserAudioProcessorEditor::SampleBrowserAudioProcessorEditor (SampleBrowserAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), sampleManager(p.getSampleManager())
{
    setLookAndFeel(&customLookAndFeel);
    
    sampleGrid = new SampleGrid(8);
    sampleGrid->addActionListener(this);
    addAndMakeVisible(sampleGrid);
    
    addAndMakeVisible(&filesButton);
    filesButton.setButtonText("Load Samples");
    filesButton.addListener(this);
    
    addAndMakeVisible(&loadSamples);
    loadSamples.setButtonText("Set Samples");
    loadSamples.addListener(this);
    
    setSize (650, 650);
}

SampleBrowserAudioProcessorEditor::~SampleBrowserAudioProcessorEditor()
{
}

//==============================================================================
void SampleBrowserAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.setGradientFill(CustomLookAndFeel::Colours::background);
    g.fillAll();
    if (uiSample !=  nullptr)
    {
        g.setColour(Colours::black);
        g.drawText(uiSample->getName(), 300, 15, 100, 50, Justification::centred);
    }
   

}

void SampleBrowserAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    sampleGrid->setBounds(75, 125, 496, 496);
    filesButton.setBounds(481, 51, 90, 30);
    loadSamples.setBounds(75, 51, 90, 30);
}

//==============================================================================
void SampleBrowserAudioProcessorEditor::buttonClicked(juce::Button *button)
{
    if (button == &filesButton)
    {
        sampleManager->loadNewSamples();
    }
    else if (button == &loadSamples)
    {
        sampleManager->updateGridRandom();
    }

}


void SampleBrowserAudioProcessorEditor::actionListenerCallback(const juce::String &message)
{
    int pad = message.getIntValue();
    uiSample = sampleManager->getSample(pad);
    repaint();
}
