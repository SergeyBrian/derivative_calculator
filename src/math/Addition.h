//
// Created by sergio on 20.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_ADDITION_H
#define DERIVATIVE_CALCULATOR_ADDITION_H
#include "BinaryOperation.h"
#include "Operation.h"

class Addition : public BinaryOperation{
public:
    Addition(Operation *l, Operation *r) : BinaryOperation(l , r) {};
    string getString() override {
        return left->getString() + " + " + right->getString();
    }
    double getNumber(double val) override {
        return left->getNumber(val) + right->getNumber(val);
    }
    Operation *getDerivative () override {
        return new Addition (left->getDerivative(), right->getDerivative());
    }
};


#endif //DERIVATIVE_CALCULATOR_ADDITION_H
