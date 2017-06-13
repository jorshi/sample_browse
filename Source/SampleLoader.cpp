/*
  ==============================================================================

    SampleLoader.cpp
    Created: 12 Jun 2017 7:12:01pm
    Author:  Jordie Shier 

  ==============================================================================
*/

#include "SampleLoader.h"


SampleLoader::SampleLoader() : Thread("Sample Loading Thread")
{
    currentlyLoading_ = nullptr;
    fileFilter_ = new WildcardFileFilter("*.wav", "", "audio file filter");
}


SampleLoader::~SampleLoader()
{
    stopThread(4000);
}


void SampleLoader::run()
{
    while(!threadShouldExit())
    {
        mutex_.enter();
        if (directories_.size() < 1 && currentlyLoading_ == nullptr)
        {
            signalThreadShouldExit();
        }
        else if (directories_.size() > 0 && currentlyLoading_ == nullptr)
        {
            currentlyLoading_ = new File(directories_.front());
            directories_.pop();
        }
        mutex_.exit();
        
        if (currentlyLoading_ != nullptr)
        {
            loadSamples();
        }

        
        std::cout << directories_.size() << "\n";
        wait(1000);
    }
}


void SampleLoader::loadSamples()
{
    Array<String> tags;
    tags.add(currentlyLoading_->getFileName());
    exploreDirectory(*currentlyLoading_, tags);
        
    
    currentlyLoading_.release();
}


void SampleLoader::exploreDirectory(const File& directory, Array<String>& tags)
{
    Array<String> newTags = tags;
    DirectoryIterator iter(directory, false, "*", File::findFilesAndDirectories);
    bool isDirectory;
    
    while (iter.next(&isDirectory, nullptr, nullptr, nullptr, nullptr, nullptr))
    {
        if (isDirectory)
        {
            newTags.add(iter.getFile().getFileName());
            exploreDirectory(iter.getFile(), newTags);
        }
        else if (fileFilter_->isFileSuitable(iter.getFile()))
        {
            
        }
    }
}


void SampleLoader::addDirectory(File& directory)
{
    mutex_.enter();
    directories_.push(directory);
    mutex_.exit();
    
    if (!isThreadRunning())
    {
        startThread();
    }
}
