/*
  ==============================================================================

    DirectoryChooser.cpp
    Created: 12 Jun 2017 4:35:56pm
    Author:  Jordie Shier 

  ==============================================================================
*/

#include "DirectoryChooser.h"

DirectoryChooser::DirectoryChooser()
{
    fileChooser_ = new FileChooser("Select sample directory");
    
}

void DirectoryChooser::getDirectory()
{
    if (fileChooser_->browseForDirectory())
    {
        int numFiles;
        File newDirectory = fileChooser_->getResult();
        Array<juce::File> results;
        
        numFiles = newDirectory.findChildFiles(results, 2, true, "*.wav");
        std::cout << numFiles;
        
    }
}
