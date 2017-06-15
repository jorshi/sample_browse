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
    
    //===========================================================================
    // Static callback function DB executions
    static int callback(void *notUsed, int argc, char **argv, char **azColName)
    {
        for (int i=0; i < argc; i++)
        {
            std::cout << azColName << " = " << (argv[i] ? argv[i] : "NULL") << "\n";
        }
        
        std::cout << "\n";
        return 0;
    }
    
    //===========================================================================
    void setupTables();
    bool runCommand(String);
    
    
    sqlite3* db_;
    bool isConnected_;
};
