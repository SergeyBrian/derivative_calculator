#include <iostream>
#include <string>

#include "src/parser/Parser.h"
#include "src/renderer/Renderer.h"

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
    Renderer renderer;

    Operation * result = parser.Parse(source);
    string final = result->getDerivative()->simplify()->getString();
    cout << result->getString() << endl;
    cout << final;
    renderer.Render("result.html", result->getString(), final);
    cout << endl;
    return 0;
}
