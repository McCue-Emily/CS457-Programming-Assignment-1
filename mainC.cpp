#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <filesystem>

using namespace std;

bool tokenize(char userInput[50]);
void nowUsing(string useDBName);
bool notUsing(char* tokens);
void create(char* tokens);
bool databaseExists(const string &s);
bool tableExists(const string &s);
void drop(char* tokens);
string use(char* tokens);
void alter();
void select();

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
        cout << "-- Using database " << useDBName << endl;
        nowUsing(useDBName);
        return true;
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
            cout << "-- Using database " << useDBName << endl;
            nowUsing(useDBName);
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

void createTB(char* useLoopTokens, string useDBName) {

}

void dropTB(char* useLoopTokens, string useDBName) {

}

bool notUsing(char* tokens) {

    //tokens = strtok(NULL, " ");
    char* token1 = tokens;
    string functionName = token1;

    cout << "function name: " << functionName << endl;

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

    } else if (strToken2 == "TABLE") {

        tokens = strtok(NULL, " ");
        char* charTableName = tokens;
        string tableName = charTableName;
        
        bool exists = tableExists(tableName);

        if (!exists) {

            string path = tokens;
            path = "/" + path;

        }

        // if second token is TABLE
            // create new file with third token as name and fourth token as header
            // as long as using a database and name is not in use yet
                // if not using database or name in use, error

    }
    
}

bool databaseExists(const string &s) {
    struct stat buffer;
    return(stat(s.c_str(), &buffer) == 0);

}

bool tableExists(const string &s) {
    struct stat buffer;
    return(stat(s.c_str(), &buffer) == 0);

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
            cout << "-- Database " << name << " deleted." << endl;
            rmdir(charDBName);
        } else {
            cout << "-- !Failed to delete " << name << " because it does not exist." << endl;
        }

    }

    // if second token is TABLE
        // delete file with table name in database that currently using
            // if not table with that name, error
        // as long as in a database
            // if not, error

}

string use(char* tokens) {

    char* token1 = tokens;

    tokens = strtok(NULL, " ");
    char* token2 = tokens;
    string path = token2;

    path = "/" + path;

    cout << path << endl;

    return path;

    // char* token1 = tokens;

    // tokens = strtok(NULL, " ");
    // char* charDBName = tokens;
    // string dbName = charDBName;



    // change directory to database name given
        // if no database with name given, error
}

void alter() {
    cout << "alter" << endl;

    // if second token is TABLE
        // open the file that is named the name given
            // if no such file with name, error
        
        // if 3rd token is ADD
            // add the header given to table
        
}

void select() {
    cout << "select" << endl;

    // read header name after select (or * which means everything)
        // store variable name

    // read table name after FROM
        // if not in database, error
        // if table doesn't exist in database, error
        // if header name doesn't exist, error

    // print contents to screen seperated by |
}




    // while((tokens = strtok(NULL, " ")) != NULL) {
    //     char* nextToken = tokens;
    //     string strNextToken = nextToken;

    //     if (strNextToken == "CREATE") {
    //         create(nextToken);
    //     } else if (strNextToken == "DROP") {
    //         drop(nextToken);
    //     } else if (strNextToken == "ALTER") {
    //         alter();
    //     } else if (strNextToken == "SELECT") {
    //         select();
    //     } else {
    //         cout << "Invalid Input." << endl;
    //     }

    // }




    // char* token1 = tokens;
    // string strToken1 = token1;

    // tokens = strtok(NULL, " ");
    // char* token2 = tokens;
    // string strToken2 = token2;

    // tokens = strtok(NULL, " ");
    // char* token3 = tokens;
    // string strToken3 = token3;

    // tokens = strtok(NULL, " ");
    // char* token4 = tokens;
    // string strToken4 = token4;

    // tokens = strtok(NULL, " ");
    // char* token5 = tokens;
    // string strToken5 = token5;

    // char* token1 = tokens;
    // string strToken1 = token1;
    // if (!strToken1.empty()) {




    //     tokens = strtok(NULL, " ");
    //     char* token2 = tokens;
    //     string strToken2 = token2;

    //     if (!strToken2.empty()) {

    //         tokens = strtok(NULL, " ");
    //         char* token3 = tokens;
    //         string strToken3 = token3;

    //         if (!strToken3.empty()) {

    //             tokens = strtok(NULL, " ");
    //             char* token4 = tokens;
    //             string strToken4 = token4;

    //             if (!strToken4.empty()) {

    //                 tokens = strtok(NULL, " ");
    //                 char* token5 = tokens;
    //                 string strToken5 = token5;

    //             }
    //         }
    //     }
    // }



    // if (strToken1 == "CREATE") {
    //     create();
    // } else if (strToken1 == "DROP") {
    //     drop();
    // } else if (strToken1 == "USE") {
    //     use();
    // } else if (strToken1 == "ALTER") {
    //     alter();
    // } else if (strToken1 == "SELECT") {
    //     select();
    // } else {
    //     cout << "Invalid Command." << endl;
    //     return;
    // }