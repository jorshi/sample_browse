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
    
    
    waveform = new WaveformComponent;
    addAndMakeVisible(waveform);
    
    header = new HeaderComponent;
    addAndMakeVisible(header);
    
    main = new MainComponent(sampleManager);
    addAndMakeVisible(main);
    
    setSize (650, 675);
}

SampleBrowserAudioProcessorEditor::~SampleBrowserAudioProcessorEditor()
{
}

//==============================================================================
void SampleBrowserAudioProcessorEditor::paint (Graphics& g)
{
    
}

void SampleBrowserAudioProcessorEditor::resized()
{
    header->setBounds(0, 0, 650, 50);
    main->setBounds(0, 50, 650, 625);
    
    sampleGrid->setBounds(77, 149, 496, 496);
    filesButton.setBounds(481, 51, 90, 30);
    loadSamples.setBounds(75, 51, 90, 30);
    
    int waveformWidth = 496;
    waveform->setBounds((getWidth() - waveformWidth) / 2, 60, waveformWidth, 79);
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
    waveform->updateSampleAndDraw(sampleManager->getSample(pad));
}
