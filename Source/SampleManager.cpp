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
    thumbnailCache_ = new AudioThumbnailCache(64);
}

void SampleManager::loadNewSamples()
{
    File directory;
    if (directoryChooser_.getDirectory(directory))
    {
        sampleLoader_->addDirectory(directory);
    }
}


void SampleManager::updateGridRandom()
{
    queuedSamples_.clear();
    String sql = "SELECT * FROM `samples` LIMIT 64;";
    if(db_.runCommand(sql, selectSampleCallback, this))
    {
        currentSamples_.swapWith(queuedSamples_);
        queuedSamples_.clear();
        updateThumbnails();
    }
}


Sample::Ptr SampleManager::getSample(int num) const
{
    if (num < currentSamples_.size())
    {
        return currentSamples_.getUnchecked(num);
    }
    
    return nullptr;
}


void SampleManager::updateThumbnails()
{
    for (auto sample = currentSamples_.begin(); sample < currentSamples_.end(); ++sample)
    {
        AudioThumbnail* newThumbnail = new AudioThumbnail(512, loader_.getFormatManager(), *thumbnailCache_);
        newThumbnail->setSource(new FileInputSource((*sample)->getFile()));
        (*sample)->setThumbnail(newThumbnail);
    }
}
