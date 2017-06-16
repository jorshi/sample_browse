/*
  ==============================================================================

    SampleGrid.h
    Created: 2 Jun 2017 5:53:46pm
    Author:  Jordie Shier 

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SamplePad.h"

//==============================================================================
/*
*/
class SampleGrid    : public Component,
                      public ButtonListener
{
public:
    SampleGrid(int numSquares);
    ~SampleGrid();

    void paint (Graphics&) override;
    void resized() override;

private:
    // Button callback
    void buttonClicked(Button* button) override;
    
    int numSquares_;
    
    OwnedArray<SamplePad> pads;
    OwnedArray<ShapeButton> buttonPads;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SampleGrid)
};
