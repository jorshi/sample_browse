/*
  ==============================================================================

    SampleManager.h
    Created: 12 Jun 2017 7:11:12pm
    Author:  Jordie Shier 

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SampleLoader.h"
#include "DirectoryChooser.h"

class SampleManager
{
public:
    
    // Default Constructor
    SampleManager();
    
    // Default Deconstructor
    ~SampleManager() {};
    
    // Prompt user to input directory for new samples
    void loadNewSamples();
    
private:
    
    ScopedPointer<SampleLoader> sampleLoader_;
    DirectoryChooser directoryChooser_;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SampleManager)
};
