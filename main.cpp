#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

void tokenize(char userInput[50]);
void create(char* tokens);
bool databaseExists(const string &s);
void drop(char* tokens);
void use();
void alter();
void select();

int main() {

    bool exit = false;
    while(exit == false) {

        char userInput[50];

        cout << "--CS457 PA1" << endl << endl;
        cin.getline(userInput, 50);
        tokenize(userInput);

        exit = true;                

    }

    return 0;
}

void tokenize(char userInput[50]) {
    
    char* tokens = strtok(userInput, " ");
    string token1 = tokens;

    if (token1 == "CREATE") {
        create(tokens);
    } else if (token1 == "DROP") {
        drop(tokens);
    } else if (token1 == "ALTER") {
        alter();
    } else if (token1 == "SELECT") {
        select();
    } else {
        cout << "Invalid Input." << endl;
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
            rmdir(charDBName);
        } else {
            cout << "error: db does not exist" << endl;
        }

    }

    // if second token is TABLE
        // delete file with table name in database that currently using
            // if not table with that name, error
        // as long as in a database
            // if not, error
}

void use(char* tokens) {
    // cout << "use" << endl;

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