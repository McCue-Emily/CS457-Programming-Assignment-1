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

        cout << "token1 = " << tokens << endl;
        token1 = tokens;
        
        tokens = strtok(NULL, " ");
        cout << "token2 = " << tokens << endl;
        token2 = tokens;
        
        tokens = strtok(NULL, " ");
        cout << "token3 = " << tokens << endl;
        token3 = tokens;

        tokens = strtok(NULL, " ");
        cout << "token4 = " << tokens << endl;
        token4 = tokens;

        tokens = strtok(NULL, " ");
        cout << "token5 = " << tokens << endl;
        token5 = tokens;

        switch (token1)
        {
        case (token1 == "CREATE"):
            /* code */
            break;
        case (token1 == "DROP"):
            break;
        case (token1 == "USE"):
            break;
        case (token1 == "ALTER"):
            break;
        case (token1 == "SELECT"):
            break;
        default:
            cout << "invalid input."
            break;
        }

}

void create() {

}

void drop() {

}

void use() {

}

void alter() {

}

void select() {

}