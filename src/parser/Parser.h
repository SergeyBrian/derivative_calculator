//
// Created by sergio on 26.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_PARSER_H
#define DERIVATIVE_CALCULATOR_PARSER_H

#include <string>
#include <vector>

#include "../math/Operation.h"
#include "../math/UnaryOperation.h"
#include "../math/BinaryOperation.h"
#include "../math/Addition.h"
#include "../math/Constant.h"
#include "../math/Variable.h"
#include "../math/Product.h"

using namespace std;

class Parser {
private:
    string source;
    Operation * result;
    vector<string> operations {
            "sin", "cos", "tan", "ctg",
            "asin", "acos", "atan",
            "sqrt", "log", "exp",
            "^", "*", "/",
            "+", "-",
            "(", ")"
    };

    template<typename T>
    int getIndex(vector<T> * vector, const T& value);
    static int convertExpressionToTokens(vector<string> * tokens, string expression);
    int parseTokens(vector<string> * queue, vector<string> * tokens);
    static void updateQueue(vector<string> * queue, const string &token);
    void updateStack(vector<string> * stack, vector<string> * queue, const string &token);
public:
    Operation * Parse(const string &expression);
};


#endif //DERIVATIVE_CALCULATOR_PARSER_H
