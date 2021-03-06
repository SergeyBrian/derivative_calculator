#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

// Global vars
string source;
bool verbose = true;
int log_c = 0;

// Functions definitions

template<typename T>
void log(const T&, bool force=false);
void getParams(int argc, char ** argv);

// Code

template<typename T>
void log(const T& text, bool force) {
    if (!(verbose||force)) return;
    cout << endl << "[" << log_c << "]: " << text << endl;
    log_c++;
}

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
    log(source);

    return 0;
}
