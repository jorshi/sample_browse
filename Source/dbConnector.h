/*
  ==============================================================================

    dbConnector.h
    Created: 7 Jun 2017 12:19:12am
    Author:  Jordie Shier 

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <sqlite3.h>

class DBConnector
{
public:
    
    // Default Constructor
    DBConnector();
    
    // Default Deconstructor
    ~DBConnector();
    
private:
    
    sqlite3* db_;
    bool isConnected_;
};
