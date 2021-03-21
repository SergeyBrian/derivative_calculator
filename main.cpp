#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

#include "src/math/Operation.h"
#include "src/math/UnaryOperation.h"
#include "src/math/BinaryOperation.h"
#include "src/math/Add.h"
#include "src/math/Constant.h"
#include "src/math/Variable.h"

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
//    getParams(argc, argv);
//    log(source);

    Constant a(12);
    Constant b(3);
    Variable x(0);
    Add sum1(&a, &x);
    Add sum2(&sum1, &b);

    cout << sum2.getDerivative()->getNumber(3);

    return 0;
}
