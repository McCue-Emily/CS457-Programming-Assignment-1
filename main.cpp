/*
Emily McCue
Programming Assignment 1
CS 457, Section 1001
Prof. Zhao
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

bool tokenize(char userInput[50]);
void nowUsing(string useDBName);
void createTB(char* useLoopTokens, string useDBName);
void dropTB(char* useLoopTokens, string useDBName);
bool notUsing(char* tokens);
void create(char* tokens);
bool databaseExists(const string &s);
bool tableExists(string totalPath);
void drop(char* tokens);
void alter(char* useLoopTokens, string useDBName);
void select(char* useLoopTokens, string useDBName);

// once that is built out, when dropping databases, check if there's tables in them and empty them out in order to delete databases
// then build out select and alter in order to alter the info in each table

int main() {

    bool exit = false;
    char userInput[50];
    
    cout << "-- CS457 PA1" << endl << endl;

    while(exit == false) {
        cin.getline(userInput, 50);
        exit = tokenize(userInput);
    }

    return 0;
}

bool tokenize(char userInput[50]) {
    
    char* tokens = strtok(userInput, " ");
    string token1 = tokens;

    if (token1 == "USE") {
        tokens = strtok(NULL, " ");
        string useDBName = tokens;
        bool exists = databaseExists(useDBName);
        if(exists) {
            cout << "-- Using database " << useDBName << endl;
            nowUsing(useDBName);
            return true;
        } else {
            cout << "-- !Failed to use database " << useDBName << " because it does not exist." << endl;
        }
        return false;
    } else {
        bool notUsingLoop = notUsing(tokens);
        return notUsingLoop;
    }

}

void nowUsing(string useDBName) {

    bool exitUseLoop = false;
    char userInputUseLoop[50];

    while (exitUseLoop == false) {

        cin.getline(userInputUseLoop, 50);
        char* useLoopTokens = strtok(userInputUseLoop, " ");
        char* charToken1 = useLoopTokens;
        string token1 = charToken1;

        if (token1 == "USE") {

            useLoopTokens = strtok(NULL, " ");
            string useDBName = useLoopTokens;

            bool exists = databaseExists(useDBName);

            if(exists) {
                cout << "-- Using database " << useDBName << endl;
                nowUsing(useDBName);
            } else {
                cout << "-- !Failed to use database " << useDBName << " because it does not exist." << endl;
            }

        } else if (token1 == "CREATE") {
            createTB(useLoopTokens, useDBName);
        } else if (token1 == "DROP") {
            dropTB(useLoopTokens, useDBName);
        } else if (token1 == "ALTER") {
            alter(useLoopTokens, useDBName);
        } else if (token1 == "SELECT") {
            select(useLoopTokens, useDBName);
        } else if (token1 == ".EXIT") {
            cout << "-- All done." << endl;
            exitUseLoop = true;
        } else {
            cout << "Invalid Input." << endl;
        }

    }

}

void createTB(char* useLoopTokens, string dbName) {

    useLoopTokens = strtok(NULL, " ");
    char* tableToken = useLoopTokens;
    string tbCheck = tableToken;

    if (tbCheck == "TABLE") {
        useLoopTokens = strtok(NULL, " ");
        char* charTBName = useLoopTokens;
        string tbName = charTBName;
        string totalPath = dbName + "/" + tbName + ".txt";

        string restOfTokens;
        char* tempVar;

        while ((useLoopTokens = strtok(NULL, " ")) != NULL) {
            tempVar = useLoopTokens;
            restOfTokens = restOfTokens + " " + tempVar;
        }

        if (!restOfTokens.empty()) {
            string original = ",";
            string replacement = " |";
            size_t pos;
            while ((pos = restOfTokens.find(original)) != string::npos) {
                restOfTokens.replace(pos, 1, replacement);
            }
            restOfTokens.erase(0,2);
            restOfTokens.erase(prev(restOfTokens.end()));
        }
        
        bool exists = tableExists(totalPath);
 
        if (!exists) {
            ofstream newTB(totalPath.c_str());
            newTB << restOfTokens;
            newTB.close();
            cout << "-- Table " << tbName << " created." << endl;
        } else {
            cout << "-- !Failed to create table " << tbName << " because it already exists." << endl;
        }
    } else {
        cout << "-- Invalid input." << endl;
    }

}

void dropTB(char* useLoopTokens, string useDBName) {

    useLoopTokens = strtok(NULL, " ");
    char* tableToken = useLoopTokens;
    string tbCheck = tableToken;

    if (tbCheck == "TABLE") {
        useLoopTokens = strtok(NULL, " ");
        char* charTBName = useLoopTokens;
        string tbName = charTBName;
        string totalPath = useDBName + "/" + tbName + ".txt";
        
        bool exists = tableExists(totalPath);

        if (exists) {
            if (remove(totalPath.c_str()) == 0) {
                cout << "-- Table " << tbName << " deleted." << endl;
            } else {
                cout << "-- Error deleting file, try again." << endl;
            }
        } else {
            cout << "-- !Failed to drop table " << tbName << " because it does not exist." << endl;

        }
    } else {
        cout << "-- Invalid input." << endl;
    }

}

bool notUsing(char* tokens) {

    char* token1 = tokens;
    string functionName = token1;

    if (functionName == "CREATE") {
        create(tokens);
    } else if (functionName == "DROP") {
        drop(tokens);
    } else if (functionName == ".EXIT") {
        cout << "-- All done." << endl;
        return true;
    } else {
        cout << "-- Invalid Input." << endl;
    }

    return false;

}

void create(char* tokens) {

    char* createToken = tokens;

    tokens = strtok(NULL, " ");
    char* token2 = tokens;
    string strToken2 = token2;

    if (strToken2 == "DATABASE") {
        tokens = strtok(NULL, " ");
        char* charDBName = tokens;
        string dbName = charDBName;
        
        bool exists = databaseExists(dbName);

        if (!exists) {
            mkdir(charDBName,0777);
            cout << "-- Database " << dbName << " created." << endl;
        } else {
            cout << "-- !Failed to create database " << dbName << " because it already exists." << endl;
        }

    } else {
        cout << "-- Invalid input." << endl;

    }
    
}

bool databaseExists(const string &s) {
    struct stat buffer;
    return(stat(s.c_str(), &buffer) == 0);

}

bool tableExists(string totalPath) {
    ifstream tbCheck;
    tbCheck.open(totalPath);
    if(tbCheck) {
        return true;
    } else {
        return false;
    }
}

void drop(char* tokens) {

    char* token1 = tokens;

    tokens = strtok(NULL, " ");
    char* token2 = tokens;
    string strToken2 = token2;

    if (strToken2 == "DATABASE") {
        tokens = strtok(NULL, " ");
        char* charDBName = tokens;
        string dbName = charDBName;
        
        bool exists = databaseExists(dbName);
        if (exists) {
            // IF THERES FILE IN DATABASE, MUST DUMP THEM BEFORE DB WILL DELETE
            rmdir(charDBName);
            cout << "-- Database " << dbName << " deleted." << endl;
        } else {
            cout << "-- !Failed to delete " << dbName << " because it does not exist." << endl;
        }

    }

}

void alter(char* useLoopTokens, string useDBName) {
    cout << "alter" << endl;

    // if second token is TABLE
        // open the file that is named the name given
            // if no such file with name, error
        
        // if 3rd token is ADD
            // add the header given to table
        
}

void select(char* useLoopTokens, string useDBName) {
    cout << "select" << endl;

    // read header name after select (or * which means everything)
        // store variable name

    // read table name after FROM
        // if not in database, error
        // if table doesn't exist in database, error
        // if header name doesn't exist, error

    // print contents to screen seperated by |
}