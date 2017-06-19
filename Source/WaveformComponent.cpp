/*
  ==============================================================================

    WaveformComponent.cpp
    Created: 16 Jun 2017 12:36:19am
    Author:  Jordie Shier 

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "WaveformComponent.h"

//==============================================================================
WaveformComponent::WaveformComponent()
{
    setLookAndFeel(&lookAndFeel);
    sample = nullptr;

}

WaveformComponent::~WaveformComponent()
{
}

void WaveformComponent::paint (Graphics& g)
{
    g.setGradientFill(CustomLookAndFeel::Colours::background);
    g.fillAll();
    
    if (sample != nullptr)
    {
        AudioThumbnail& thumbnail = sample->getThumbnail();
        if (thumbnail.getNumChannels() == 0)
        {
            std::cout << "No File Loaded";
        }
        else
        {
            g.setColour(Colours::whitesmoke);
            thumbnail.drawChannel(g, getLocalBounds(), 0.0, thumbnail.getTotalLength(), 0, 1.0f);
        }
    }
    
    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 2);   // draw an outline around the component
}

void WaveformComponent::resized()
{

}

void WaveformComponent::updateSampleAndDraw(Sample::Ptr s)
{
    sample = s;
    repaint();
}
