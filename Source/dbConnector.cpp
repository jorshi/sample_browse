/*
  ==============================================================================

    dbConnector.cpp
    Created: 7 Jun 2017 12:19:12am
    Author:  Jordie Shier 

  ==============================================================================
*/

#include "dbConnector.h"


DBConnector::DBConnector()
{
    
    if (sqlite3_open("test.db", &db_))
    {
        isConnected_ = false;
        std::cout << "Failed to open DB";
    }
    else
    {
        isConnected_ = true;
        std::cout << "DB connection established\n";
        
        // Setup Tables
        setupTables();
    }
}

DBConnector::~DBConnector()
{
    sqlite3_close(db_);
    std::cout << "DB Connection successfully closed\n";
}


bool DBConnector::runCommand(juce::String command)
{
    char *zErrMsg = 0;
    int rc = sqlite3_exec(db_, command.toRawUTF8(), callback, 0, &zErrMsg);
    
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL ERROR: " << zErrMsg << "\n";
        return false;
    }
    
    return true;
}



void DBConnector::setupTables()
{
    // Check whether tables exist
    if (!runCommand("SELECT 1 FROM `samples` LIMIT 1"))
    {
        // Need to setup tables
        String sql = "CREATE TABLE `samples`(" \
            "id INT PRIMARY KEY NOT NULL" \
            ");";
        
        std::cout << runCommand(sql);
        
    }
    else
    {
        runCommand("DROP TABLE `samples`;");
        std::cout << "Tables setup\n";
    }
    
}



