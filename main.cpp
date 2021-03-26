#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>

#include "src/parser/Parser.h"

using namespace std;

// Global vars
string source;
bool verbose = true;
int log_c = 0;

// Functions definitions

void getParams(int argc, char ** argv);

// Code

void getParams(int argc, char ** argv) {
    if (argc > 1) {
        string arg = argv[1];
        source = arg;
        if (argc > 2) {
            arg = argv[2];
            if (arg=="-v") verbose = true;
        }
        return;
    }
    cout << "Enter expression: ";
    cin >> source;
}

int main(int argc, char ** argv) {
    getParams(argc, argv);

    Parser parser;
    Operation * result = parser.Parse(source);
    cout << "\n\nResult: " << result->getDerivative()->getString();
    return 0;
}
