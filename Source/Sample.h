/*
  ==============================================================================

    Sample.h
    Created: 15 Jun 2017 12:36:16pm
    Author:  Jordie Shier 

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "dbConnector.h"

class Sample
{
public:
    
    // Default Constructor
    Sample() {};
    
    // Constructor
    Sample(int id, String name, String fullPath, double start, double stop);
    
    // Default Deconstuctor
    ~Sample() {};
    
    // Save a new sample instance
    bool save(const DBConnector& db);
    
    bool saveTagsForSample(const DBConnector& db, const Array<String>& tags);
    
    // Getters
    int getId() const { return id_; };
    const File& getFile() const { return path_; };
    const String& getName() const { return name_; };
    
    
private:
    
    int id_;
    String name_;
    File path_;
    
    double startTime_;
    double stopTime_;
};
