//
// Created by sergio on 26.03.2021.
//

#include "Parser.h"
#include <iostream>

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
            int operator_precedence = getIndex(&operations, token);
            int top_operator_precedence = getIndex(&operations, stack->back());

            if (operator_precedence <= top_operator_precedence) stack->push_back(token);
            else {
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
 * @param tokens vector generated in `convertExpressionToTokens` function
 * @return 0 - Success
 * 1 - Invalid token
 */
int Parser::parseTokens(vector<string> * queue, vector<string> * tokens) {
    vector<string> stack;

    // Parse all tokens
    for (auto token : *tokens) {
        std::cout << "\n: " << token;
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
    parseTokens(&queue, &tokens);

    return result;
}
