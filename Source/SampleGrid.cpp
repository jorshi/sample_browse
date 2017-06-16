/*
  ==============================================================================

    SampleGrid.cpp
    Created: 2 Jun 2017 5:53:46pm
    Author:  Jordie Shier 

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SampleGrid.h"

//==============================================================================
SampleGrid::SampleGrid(int numSquares)
{
    numSquares_ = numSquares;
    
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    SamplePad* newPad = new SamplePad;
    addAndMakeVisible(newPad);
    pads.add(newPad);
    
    Path buttonPath;
    buttonPath.addRoundedRectangle(0, 0, 50, 50, 2);
    
    Colour normal = Colours::azure;
    Colour over = Colours::burlywood;
    Colour down = Colours::aqua;
    ShapeButton* newButton;
    
    int count = 0;
    for (int i = 0; i < numSquares_; ++i)
    {
        for (int j = 0; j < numSquares_; ++j)
        {
            newButton = new ShapeButton("Pad " + std::to_string(count), Colour::fromRGB((i*10) + 100, (j*10) + 100, 150 - (i+j)*2), over, down);
            newButton->setShape(buttonPath, true, true, false);
            newButton->addListener(this);
            addAndMakeVisible(newButton);
            buttonPads.insert(count++, newButton);
        }
    }
}

SampleGrid::~SampleGrid()
{
}

void SampleGrid::paint (Graphics& g)
{
    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
}

void SampleGrid::resized()
{
    float buttonWidth = static_cast<float>(getWidth()) / numSquares_;
    
    int count = 0;
    for (int i = 0; i < numSquares_; ++i)
    {
        for (int j = 0; j < numSquares_; ++j)
        {
            buttonPads.getUnchecked(count)->setBounds((j*buttonWidth)+1, (i*buttonWidth)+1, buttonWidth-2, buttonWidth-2);
            count++;
        }
    }
}

void SampleGrid::buttonClicked(juce::Button *button)
{
    std::cout << button->getName() << "\n";
}
