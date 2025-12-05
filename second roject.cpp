#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<int> ArryNumber;   // store digits as numbers
vector<char> Arraysymbol; // store operators as chars
string Phrase;
char c; 
void TakeInfix() {
    cout << "Enter phrase (infix)(with out space): ";
    cin >> Phrase;
    for (int i = 0; i < Phrase.size(); i++) {
        c = Phrase[i];
        if (isdigit(c)) {
            ArryNumber.push_back(c - '0'); // convert char to int ('3' > 3) be couse ArrayNumber is int array not char array, so every thing in it should be int
        }
        if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^' || c == '(') {
            Arraysymbol.push_back(c);
        }
    }
}


void InfixToPostfix() {
    cout << "postfix is: ";
    for(int i = 0 ; i<Phrase.size() ; i++) {
        c = Phrase[i];
        if (c == ')') {
            for (int n : ArryNumber) {
                cout << n << "";
            }
            ArryNumber.clear();
            cout << Arraysymbol.back();
            if(Arraysymbol.back()) { //to remove operator
                Arraysymbol.pop_back();
            }
            if(Arraysymbol.back() == '(' ) { //ine 43-45 : to remove ( after poping opertor
                Arraysymbol.pop_back();
            }
            
        }
    }
}


void InfixToPrefix() {
    vector<string> ArryNumber; 
    char b;
    string a[2];
    string new_element_stack;
    for (int i = 0; i < Phrase.size(); i++) {
        if (!Arraysymbol.empty() && ArryNumber.size() >= 2) {
            char c = Phrase[i];
            if (c == ')') {
                b = Arraysymbol.back();
                Arraysymbol.pop_back();
                for (int j = 0; j < 2; j++) { //to get tow numbers
                    a[j] = ArryNumber.back();
                    ArryNumber.pop_back();
                }
                new_element_stack = string(1, b) + a[1] + a[0]; //b is char abd need to cinvert to str, that 1 is lengh of str, means b which converted to str is only one character
                ArryNumber.push_back(new_element_stack); //append to Arrynumber
            }
        }   
    cout << "prefix: "<< ArryNumber.back();
    }
}


int main() {
    TakeInfix();
    InfixToPostfix();
    InfixToPrefix();
}
