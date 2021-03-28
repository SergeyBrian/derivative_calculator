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
#include "../math/Pow.h"
#include "../math/Sin.h"
#include "../math/Cos.h"
#include "../math/Tan.h"
#include "../math/Arcsin.h"
#include "../math/Arccos.h"
#include "../math/Atan.h"
#include "../math/Log.h"
#include "../math/Exp.h"
#include "../math/Sqrt.h"



using namespace std;

class Parser {
private:
    string source;
    Operation * result;
    vector<string> operations {
            "sin", "cos", "tan",
            "asin", "acos", "atan",
            "sqrt", "log", "exp",
            "^", "*", "/",
            "+", "-",
            "(", ")"
    };

    vector<string> precedence4 {"^"};
    vector<string> precedence3 {"*", "/"};
    vector<string> precedence2 {"+", "-"};

    template<typename T>
    int getIndex(vector<T> * vector, const T& value);
    static int getPrecedence(const string& token);
    static int convertExpressionToTokens(vector<string> * tokens, string expression);
    int parseTokens(vector<string> * queue, vector<string> * tokens);
    static void updateQueue(vector<string> * queue, const string &token);
    void updateStack(vector<string> * stack, vector<string> * queue, const string &token);
    int updateOperationsStack(vector<Operation *> * stack, const string& token);
    int convertQueueToOperation(vector<string> * queue);
public:
    Operation * Parse(const string &expression);
};


#endif //DERIVATIVE_CALCULATOR_PARSER_H
