#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<int> ArryNumber;   // store digits as numbers
vector<char> Arraysymbol; // store operators as chars
string Phrase;
char c; 
void TakeInputAsInfix() {
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
    cout << endl;
    string new_element_stack;
    vector<string> NewArraynumber;   // numbers as strings
    char symbol;
    string a[2];
    for (int x : ArryNumber) {
        NewArraynumber.push_back(to_string(x));
    }
    for (int i = 0 ; i<Phrase.size() ; i++) {
        if (c == ')') {
            symbol = Arraysymbol.back();
            for (int j ; j<2 ; j++) {
                a[j] = NewArraynumber.back();
            }
            new_element_stack = string(1, symbol) + a[0] + a[1];
            Arraysymbol.pop_back();
            NewArraynumber.pop_back();
            NewArraynumber.pop_back();
        }
        if (NewArraynumber.empty() == true) {
            cout << "prefix: "<< new_element_stack;
        }
    }
}    

int main() {
    TakeInputAsInfix();
    InfixToPostfix();
    InfixToPrefix();
}
