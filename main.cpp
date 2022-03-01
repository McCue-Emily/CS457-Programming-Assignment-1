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
        
        tokens = strtok(NULL, " ");
        cout << "token2 = " << tokens << endl;
        
        tokens = strtok(NULL, " ");
        cout << "token3 = " << tokens << endl;

        tokens = strtok(NULL, " ");
        cout << "token4 = " << tokens << endl;

        tokens = strtok(NULL, " ");
        cout << "token5 = " << tokens << endl;

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