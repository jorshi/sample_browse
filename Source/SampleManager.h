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
#include "Sample.h"
#include "DirectoryChooser.h"
#include "dbConnector.h"

class SampleManager
{
public:
    
    // Default Constructor
    SampleManager();
    
    // Default Deconstructor
    ~SampleManager() {};
    
    // Prompt user to input directory for new samples
    void loadNewSamples();
    
    void updateGridRandom();
    
private:
    
    static int selectSampleCallback(void *param, int argc, char **argv, char **azCol)
    {
        SampleManager* manager = reinterpret_cast<SampleManager*>(param);
        
        if (argc == 5)
        {
            Sample::Ptr newSample = new Sample();
            newSample->setId(atoi(argv[0]));
            newSample->setName(String(argv[1]));
            newSample->setPath(String(argv[2]));
            manager->queuedSamples_.add(newSample);
        }

        return 0;
    }
    
    ReferenceCountedArray<Sample> currentSamples_;
    ReferenceCountedArray<Sample> queuedSamples_;
    
    ScopedPointer<SampleLoader> sampleLoader_;
    DirectoryChooser directoryChooser_;
    DBConnector db_;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SampleManager)
};
