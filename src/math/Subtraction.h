//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_SUBTRACTION_H
#define DERIVATIVE_CALCULATOR_SUBTRACTION_H
#include "BinaryOperation.h"

class Subtraction : public BinaryOperation{
public:
    Subtraction(Operation *l, Operation *r) : BinaryOperation(l, r) {};
    string getString() override {
        return "(" + left->getString() + ") - (" + right->getString() + ")";
    }
    double getNumber(double val) override {
        return left->getNumber(val)-right->getNumber(val);
    }
    Operation *getDerivative() override {
        return new Subtraction(left->getDerivative(), right->getDerivative());
    }
};


#endif //DERIVATIVE_CALCULATOR_SUBTRACTION_H
