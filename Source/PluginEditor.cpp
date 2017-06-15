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
    addAndMakeVisible(sampleGrid);
    
    addAndMakeVisible(&filesButton);
    filesButton.setButtonText("Load Samples");
    filesButton.addListener(this);
    
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
}

void SampleBrowserAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    sampleGrid->setBounds(75, 125, 496, 496);
    filesButton.setBounds(530, 15, 90, 30);
}

//==============================================================================
void SampleBrowserAudioProcessorEditor::buttonClicked(juce::Button *button)
{
    sampleManager->loadNewSamples();
}
