/*
  ==============================================================================

    SampleManager.cpp
    Created: 12 Jun 2017 7:11:12pm
    Author:  Jordie Shier 

  ==============================================================================
*/

#include "SampleManager.h"

SampleManager::SampleManager()
{
    sampleLoader_ = new SampleLoader;
}

void SampleManager::loadNewSamples()
{
    File directory;
    if (directoryChooser_.getDirectory(directory))
    {
        sampleLoader_->addDirectory(directory);
    }
}

