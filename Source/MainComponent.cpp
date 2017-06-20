/*
  ==============================================================================

    MainComponent.cpp
    Created: 19 Jun 2017 4:48:24pm
    Author:  Jordie Shier 

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent(SampleManager* s) : sampleManager(s)
{
    setLookAndFeel(&customLookAndFeel);
    
    sampleGrid = new SampleGrid(8);
    sampleGrid->addActionListener(this);
    addAndMakeVisible(sampleGrid);
    
    waveform = new WaveformComponent();
    addAndMakeVisible(waveform);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (Graphics& g)
{
    g.setGradientFill(CustomLookAndFeel::Colours::background);
    g.fillAll();
    
}

void MainComponent::resized()
{
    sampleGrid->setBounds(77, 99, 496, 496);
    waveform->setBounds(77, 10, 496, 79);
}


void MainComponent::actionListenerCallback(const juce::String &message)
{
    int pad = message.getIntValue();
    waveform->updateSampleAndDraw(sampleManager->getSample(pad));
}
