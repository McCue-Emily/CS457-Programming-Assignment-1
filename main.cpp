#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

vector<string> tokenize(const char *str, char c = ' ');

int main() {

    bool exit = false;
    while(exit == false) {

        // const char *userInput;
        // vector <string> tokens;

        string strUserInput;

        cout << "--CS457 PA1" << endl << endl;

        // userInput[] = strUserInput;
        // tokens = tokenize(userInput);

        getline(cin, strUserInput);
        char userInput[] = strUserInput;

        char str[] = "Geeks for Geeks";
        char *token;
        char *rest = str;
    
        while ((token = strtok_r(rest, " ", &rest)))
            printf("%s\n", token);
    

        // stringstream check1(userInput);

        // string intermediate;

        // while (getline(check1, intermediate, ' ')) {
        //     tokens.push_back(intermediate);
        // }

        // for(int i = 0; i < tokens.size(); i++) {
        //     cout << tokens[i] << '\n';
        // }


        exit = true;                

    }

    return 0;
}

vector<string> tokenize(const char *str, char c) {

    vector<string> result;

    do {

        const char *begin = str;

        while (*str != c && *str) {
            str++;
        }

        result.push_back(string(begin, str));

    } while (0 != *str++);

    return result;

}