#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

bool tokenizeClosed(char userInput[50]);
bool tokenizeOpen(char userInput[50], string dbName);
void createDB(char* tokens);
string createTB(char* tokens);
bool databaseExists(const string &s);
bool tableExists(const string &s);
void drop(char* tokens, char userInput[50]);
string use(string dbName);
void alter();
void select();

int main() {

    bool exit = false;
    bool exit1 = false;
    char userInput[50];
    
    cout << "-- CS457 PA1" << endl << endl;

    // cin.getline(userInput, 50);
    // char* tokens = strtok(userInput, " ");
    // string token1 = tokens;

    while(exit == false) {

        cin.getline(userInput, 50);
        char* tokens = strtok(userInput, " ");
        string token1 = tokens;
        cout << "user input: " << userInput << endl;

        if (token1 == "USE") {
            char* useToken = tokens;
            tokens = strtok(NULL, " ");
            char* token2 = tokens;
            string dbName = token2;
            cout << "-- Using database " << dbName << endl;
            string dbPath = use(dbName);
            cout << "dbPath: " << dbPath << endl;
            // operating within a directory (have access to different functions)

            while(exit1 == false) {
                cin.getline(userInput, 50);
                char* tokens = strtok(userInput, " ");
                string token1 = tokens;
                exit = tokenizeOpen(userInput, dbPath);
            }
            // must exit and restart program in order to be able to create or drop databases

            return 0;

        } else {
            exit = tokenizeClosed(userInput);
            // not operating within a directory (have limited access to functions)
        }

    }

    return 0;
}

/*
If "USE" has not happened and not working within a directory
*/
bool tokenizeClosed(char userInput[50]) {
    
    char* tokens = strtok(userInput, " ");
    string token1 = tokens;
    cout << token1 << endl;

    if (token1 == "CREATE") {

        char* createToken = tokens;
        tokens = strtok(NULL, " ");
        char* token2 = tokens;
        string strToken2 = token2;
        // either database or table stored

        if (strToken2 == "DATABASE") {
            // create database
            cout << "create working" << endl;
            createDB(tokens);
        } else {
            cout << "Invalid Input." << endl;
            // didn't input database and can't create anything else right now
        }

    } else if (token1 == "DROP") {
        drop(tokens, userInput);
    } else if (token1 == ".EXIT") {
        cout << "-- All done." << endl;
        return true;
    } else {
        cout << "Close : Invalid Input." << endl;
    }
    return false;

}

/*
If "USE" has happened successfully and operating within a database (directory)
*/
bool tokenizeOpen(char userInput[50], string dbName) {
    
    char* tokens = strtok(userInput, " ");
    string token1 = tokens;

    if (token1 == "CREATE") {

        char* createToken = tokens;
        tokens = strtok(NULL, " ");
        char* token2 = tokens;
        string strToken2 = token2;
        // either database or table stored

        if (strToken2 == "TABLE") {
            //create table

            string tbName = createTB(tokens);

            if (tbName == "f") {
                // table already exists, exit
                return false;
            }

            string completePathName = dbName + tbName;
            cout << "complete path name: " << completePathName << endl;
            // create complete path name

            ofstream tbFile(completePathName);
            // open file in directory, with the table name specified

        } else {
            cout << "Invalid Input." << endl;
            // didn't input database or table and can't create anything else right now
        }

    } else if (token1 == "DROP") {
        drop(tokens, userInput);
    } else if (token1 == "ALTER") {
        alter();
    } else if (token1 == "SELECT") {
        select();
    } else if (token1 == ".EXIT") {
        cout << "-- All done." << endl;
        return true;
    } else {
        cout << "open: Invalid Input." << endl;
    }
    return false;

}

string use(string dbName) {

    // char* useToken = tokens;
    // tokens = strtok(NULL, " ");
    // char* token2 = tokens;
    // string dbName = token2;

    string dbPath = "./" + dbName;
    // ./dbName/fileName

    return dbPath;

    // char* token1 = tokens;

    // tokens = strtok(NULL, " ");
    // char* charDBName = tokens;
    // string dbName = charDBName;



    // change directory to database name given
        // if no database with name given, error
}

void createDB(char* tokens) {

    cout << "createDB accessed " << endl;

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
}

string createTB(char* tokens) {

    tokens = strtok(NULL, " ");
    char* charTableName = tokens;
    string tableName = charTableName;
    
    bool exists = tableExists(tableName);

    if (!exists) {
        string path = tokens;
        path = "/" + path;
        cout << "path: " << path << endl;
        return path;
    } else {
        cout << "-- !Failed to create table " << tableName << " because it already exists." << endl;
        //string failed = "f";
        return "failed";
    }

        // if second token is TABLE
            // create new file with third token as name and fourth token as header
            // as long as using a database and name is not in use yet
                // if not using database or name in use, error


}

bool databaseExists(const string &s) {
    struct stat buffer;
    return(stat(s.c_str(), &buffer) == 0);

}

bool tableExists(const string &s) {
    struct stat buffer;
    return(stat(s.c_str(), &buffer) == 0);

}

void drop(char* tokens, char userInput[50]) {

    char* dropToken = tokens;
    cout << "user: " <<  userInput[2] << endl;
    tokens = strtok(userInput, " ");
    cout << "token 1: " << tokens << endl;
    tokens = strtok(NULL, " ");

    cout << "token 2 " <<  tokens << endl;
    cout << "past strtok" << endl;

    char* token2 = tokens;
    cout << token2 << endl;
    string strToken2 = token2;

    // string strToken2 = token2;
    // cout << "token 2 " << strToken2 << endl;

    if (strToken2 == "DATABASE") {
        cout << "second token is database" << endl;
        tokens = strtok(NULL, " ");
        char* charName = tokens;
        string name = charName;
        
        bool exists = databaseExists(name);
        if (exists) {
            cout << "-- Database " << name << " deleted." << endl;
            rmdir(charName);
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

    //

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