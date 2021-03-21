//
// Created by sergio on 20.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_ADD_H
#define DERIVATIVE_CALCULATOR_ADD_H
#include "BinaryOperation.h"
#include "Operation.h"

class Add : public BinaryOperation{
public:
    Add(Operation *l, Operation *r) : BinaryOperation(l ,r) {};
    string getString() override {
        return left->getString() + "+" + right->getString();
    }
    double getNumber(double val) override {
        return left->getNumber(val) + right->getNumber(val);
    }
    Operation *getDerivative () override {
        return new Add (left->getDerivative(), right->getDerivative());
    }
};


#endif //DERIVATIVE_CALCULATOR_ADD_H
