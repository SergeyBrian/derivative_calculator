#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>

#include "src/math/Operation.h"
#include "src/math/UnaryOperation.h"
#include "src/math/BinaryOperation.h"
#include "src/math/Addition.h"
#include "src/math/Constant.h"
#include "src/math/Variable.h"
#include "src/math/Product.h"

using namespace std;

// Global vars
string source;
bool verbose = true;
int log_c = 0;

// Functions definitions

void getParams(int argc, char ** argv);
void pushUnaryOperator(string basicString, vector<string> *pVector)
void pushBinaryOperator(string basicString, vector<string> *pVector)
int parseExpression(vector<Operation *> * operands, vector<Operation *> * operators, string expression);

// Code

void pushUnaryOperator(string basicString, vector<string> *pVector);

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

/*!
 *
 * @param parsed vector to which the result of parsing will be written
 * @param expression string containing math expression
 * @return result of parsing:
 * 0 - Success
 */
int parseExpression(vector<Operation *> * operands, vector<Operation *> * operators, string expression) {
    vector<string> tokens;
    string token;
    // Generates vector of tokens to be processed later
    for (int i = 0; i < expression.length(); i++) {
        char sym = expression[i];
        if (token.length()) {
            if ((token[0] == 'x') ||
            (isdigit(token[0]) && !isdigit(sym)) ||
            (isalpha(token[0]) && !isalpha(sym)) ||
            (ispunct(sym)) ||
            (ispunct(token[0]))) {
                tokens.push_back(token);
                token.clear();
                token += sym;
            } else token+=sym;
        } else token += (sym);

        if (i == expression.length() - 1) {
            tokens.push_back(token);
        }
    }

    // Using shunting yard algorithm
    cout << endl;
    for (int i = 0; i < tokens.size(); i++) {
        token = tokens[i];
        if (isdigit(token[0])) operands->push_back(new Constant(stod(token)));
        else if (token[0]=='x') operands->push_back(new Variable(0));
        else if (isalpha(token[0])) pushUnaryOperator(token, &tokens)
    }

    return 0;
}

void pushUnaryOperator(string basicString, vector<string> *pVector) {

}

int main(int argc, char ** argv) {
    getParams(argc, argv);
//    log(source);
    vector<Operation *> operands;
    vector<Operation *> operators;
    parseExpression(&operands, &operators, source);

//    Constant a(12);
//    Constant b(3);
//    Variable x(0);
//    Product prod(&a, &x);
//    Addition sum2(&prod, &b);
//
//    cout << sum2.getString() << endl << sum2.getDerivative()->getString() << endl;
//    cout << sum2.getDerivative()->getNumber(0);

    return 0;
}
