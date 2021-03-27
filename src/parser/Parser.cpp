//
// Created by sergio on 26.03.2021.
//

#include "Parser.h"
#include <iostream>
#include <algorithm>

/*!
 * Returns index of element with given value in given vector
 * @tparam T
 * @param vector
 * @param value
 * @return index of element, -1 if element not in vector
 */
template<typename T>
int Parser::getIndex(vector<T> * vector, const T& value) {
    auto element = find(vector->begin(), vector->end(), value);
    if (element != vector->end()) return element - vector->begin();
    return -1;
}


/*!
 * Put token to the end of queue
 * @param queue
 * @param token
 */
void Parser::updateQueue(vector<string> * queue, const string& token) {
    queue->push_back(token);
}


int Parser::getPrecedence(const string& token) {
    if (token == "^") return 4;
    if (token == "*" || token == "/") return 3;
    if (token == "+" || token == "-") return 2;
    if (token == "(") return 1;
    return 5;
}


/*!
 * Performs the shunting yard algorithm stack update
 * @param stack
 * @param queue
 * @param token
 */
void Parser::updateStack(vector<string> * stack, vector<string> * queue, const string& token) {
    if (stack->empty() || token=="(") {
        stack->push_back(token);
    } else {
        if (token == ")") {
            while (stack->back() != "(") {
                updateQueue(queue, stack->back());
                stack->pop_back();
            } stack->pop_back();
        } else {
            int operator_precedence = getPrecedence(token);
            int top_operator_precedence = getPrecedence(stack->back());
//            cout << "\n" << top_operator_precedence;
//            cout << "\ntoken: " << token << " precedence: " << operator_precedence;
            if ((operator_precedence > top_operator_precedence) ||
            (operator_precedence==top_operator_precedence && token != "^")) stack->push_back(token);
            else if (stack->back() != "("){
                updateQueue(queue, stack->back());
                stack->pop_back();
                updateStack(stack, queue, token);
            }
        }
    }
}

/*!
 *
 * @param tokens vector to which the result of parsing will be written
 * @param expression string containing math expression
 * @return result of parsing:
 * 0 - Success
 * 1 - Expression is empty
 */
int Parser::convertExpressionToTokens(vector<string> * tokens, string expression) {
    string token;
    if (!expression.length()) return 1;
    // Generates vector of tokens to be processed later
    for (int i = 0; i < expression.length(); i++) {
        char sym = expression[i];
        if (token.length()) {
            if ((token[0] == 'x') ||
                (isdigit(token[0]) && !isdigit(sym)) ||
                (isalpha(token[0]) && !isalpha(sym)) ||
                (ispunct(sym)) ||
                (ispunct(token[0]))) {
                tokens->push_back(token);
                token.clear();
                token += sym;
            } else token+=sym;
        } else token += (sym);

        if (i == expression.length() - 1) {
            tokens->push_back(token);
        }
    }

    return 0;
}

/*!
 *
 * @param queue vector to which parsing result will be written
 * @param tokens vector generated in convertExpressionToTokens function
 * @return 0 - Success
 * 1 - Invalid token
 */
int Parser::parseTokens(vector<string> * queue, vector<string> * tokens) {
    vector<string> stack;

    // Parse all tokens
    for (auto token : *tokens) {
        if (isdigit(token[0]) || token[0] == 'x') updateQueue(queue, token); // Push digits and variables to queue
        else if (find(operations.begin(), operations.end(), token) != operations.end()) {
            updateStack(&stack, queue, token);
        }
        else return 1;
    }

    // Move tokens remaining in stack to queue
    while (!stack.empty()) {
        updateQueue(queue, stack.back());
        stack.pop_back();
    }

    return 0;
}

int Parser::updateOperationsStack(vector<Operation *> * stack, const string& token) {
    vector<string> unaryOperators {
            "sin", "cos", "tan",
            "asin", "acos", "atan",
            "sqrt", "log", "exp"
    };
    vector<string> binaryOperators {
            "^", "*", "/",
            "+", "-"
    };
    if (getIndex(&binaryOperators, token) + 1) {
        if (stack->size() < 2) return 1;

        if (token=="*") stack->push_back(new Product(stack->end()[-2], stack->back()));
        else if (token=="^") stack->push_back(new Pow(stack->end()[-2], stack->back()));
        else if (token=="/") stack->push_back(new Division(stack->end()[-2], stack->back()));
        else if (token=="+") stack->push_back(new Addition(stack->end()[-2], stack->back()));
        else if (token=="-") stack->push_back(new Subtraction(stack->end()[-2], stack->back()));

        stack->erase(stack->end()-3, stack->end() - 1);
//        if (stack->size() > 1) updateOperationsStack(stack, token);
    } else {
        if (token=="sin") stack->push_back(new Sin(stack->back()));
        else if (token=="cos") stack->push_back(new Cos(stack->back()));
        else if (token=="tan") stack->push_back(new Tan(stack->back()));
        else if (token=="asin") stack->push_back(new Arcsin(stack->back()));
        else if (token=="acos") stack->push_back(new Arccos(stack->back()));
        else if (token=="atan") stack->push_back(new Atan(stack->back()));
        else if (token=="sqrt") stack->push_back(new Sqrt(stack->back()));
        else if (token=="log") stack->push_back(new Log(stack->back()));
        else if (token=="exp") stack->push_back(new Exp(stack->back()));

        stack->erase(stack->end()-2);
    }
    return 0;
}


/*!
 * Use stack machine to translate RPN to object of Operation class
 * @param queue
 * @param operation
 * @return 0 - Success
 * 1 - Not enough operands for binary operation
 * 2 - Too many operands for unary operation
 */
int Parser::convertQueueToOperation(vector<string> * queue) {
    vector<Operation *> stack;

    for (auto token : *queue) {
        if (isdigit(token[0])) stack.push_back(new Constant(stod(token)));
        else if (token == "x") stack.push_back(new Variable());

        else {
            switch(updateOperationsStack(&stack, token)) {

                case 1:
                    return 1;
                case 2:
                    return 2;
            }
        }
    }

    result = stack.back();

    return 0;
}


/*!
 * Perform parsing for given expression
 * @param expression string with source expression
 * @return pointer to parsed data
 */
Operation * Parser::Parse(const string &expression) {
    source = expression;
    vector<string> tokens;
    vector<string> queue;

    convertExpressionToTokens(&tokens, source);
    if (parseTokens(&queue, &tokens)) cout << "\n\nERROR! Invalid token!";
    switch (convertQueueToOperation(&queue)) {
        case 1:
            cout << "\n\nERROR! Not enough operands for binary operation!";
            exit(1);
        case 2:
            cout << "\n\nERROR! Too many operands for unary operation!";
            exit(2);
    }

    return result;
}
