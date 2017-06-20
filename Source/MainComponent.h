/*
  ==============================================================================

    MainComponent.h
    Created: 19 Jun 2017 4:48:24pm
    Author:  Jordie Shier 

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "CustomLookAndFeel.h"
#include "SampleGrid.h"
#include "WaveformComponent.h"
#include "SampleManager.h"

//==============================================================================
/*
*/
class MainComponent    : public Component,
                         public ActionListener
{
public:
    MainComponent(SampleManager* s);
    ~MainComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    
    // Action callback
    void actionListenerCallback(const String& message) override;
    
//==============================================================================
    
    CustomLookAndFeel customLookAndFeel;
    
    // Components
    ScopedPointer<SampleGrid> sampleGrid;
    ScopedPointer<WaveformComponent> waveform;
    
    SampleManager* sampleManager;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
