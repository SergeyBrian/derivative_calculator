#include <iostream>
#include <string>

#include "src/parser/Parser.h"

using namespace std;

// Global vars
string source;

// Functions definitions

void getParams(int argc, char ** argv);

// Code

void getParams(int argc, char ** argv) {
    if (argc > 1) {
        string arg = argv[1];
        source = arg;
        return;
    }
    cout << "Enter expression: ";
    cin >> source;
}

int main(int argc, char ** argv) {
    getParams(argc, argv);

    Parser parser;

    Operation * result = parser.Parse(source)->simplify();
    string final = result->getDerivative()->getString();
    cout << result->getString() << endl;
    cout << final;
    return 0;
}
