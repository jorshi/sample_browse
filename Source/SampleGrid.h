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
#include "PadButton.h"

//==============================================================================
/*
*/
class SampleGrid    : public Component,
                      public ActionListener,
                      public ActionBroadcaster
{
public:
    SampleGrid(int numSquares);
    ~SampleGrid();

    void paint (Graphics&) override;
    void resized() override;

private:    
    void actionListenerCallback(const String& message) override;
    
    int numSquares_;
    
    OwnedArray<PadButton> buttonPads;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SampleGrid)
};
