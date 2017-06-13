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
    int rc;
    rc = sqlite3_open("test.db", &db_);
    
    if (rc)
    {
        isConnected_ = false;
        std::cout << "Failed to open DB";
    }
    else
    {
        isConnected_ = true;
        std::cout << "DB connection established\n";
    }
}

DBConnector::~DBConnector()
{
    sqlite3_close(db_);
    std::cout << "DB Connection successfully closed\n";
}



