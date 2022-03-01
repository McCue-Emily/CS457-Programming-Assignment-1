#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstring>

using namespace std;

void tokenize(char* tokens);
void create();
void drop();
void use();
void alter();
void select();

int main() {

    bool exit = false;
    while(exit == false) {

        char userInput[50];

        cout << "--CS457 PA1" << endl << endl;
        cin.getline(userInput, 50);
        char* tokens = strtok(userInput, " ");
        tokenize(tokens);

        exit = true;                

    }

    return 0;
}

void tokenize(char* tokens) {

        char* token1 = tokens;
        
        tokens = strtok(NULL, " ");
        char* token2 = tokens;
        
        tokens = strtok(NULL, " ");
        char* token3 = tokens;

        tokens = strtok(NULL, " ");
        char* token4 = tokens;

        tokens = strtok(NULL, " ");
        char* token5 = tokens;

        //cout << token1 << endl << token2 << endl << token3 << endl << token4 << endl << token5 << endl;

        if (token1 == "CREATE") {
            create();
        } else if (token1 == "DROP") {
            drop();
        } else if (token1 == "USE") {
            use();
        } else if (token1 == "ALTER") {
            alter();
        } else if (token1 == "SELECT") {
            select();
        }

}

void create() {
    cout << "create" << endl;
}

void drop() {
    cout << "drop" << endl;
}

void use() {
    cout << "use" << endl;
}

void alter() {
    cout << "alter" << endl;
}

void select() {
    cout << "select" << endl;
}