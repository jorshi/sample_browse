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

class Sample : public ReferenceCountedObject
{
public:
    
    typedef ReferenceCountedObjectPtr<Sample> Ptr;
    
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
    
    // Setters
    void setId(const int& id) { id_ = id; };
    void setName(const String& name) { name_ = name; };
    void setPath(const String& path) { path_ = File(path); };
    
    
private:
    
    int id_;
    String name_;
    File path_;
    
    double startTime_;
    double stopTime_;
};
