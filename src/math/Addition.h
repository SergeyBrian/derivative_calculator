//
// Created by sergio on 20.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_ADDITION_H
#define DERIVATIVE_CALCULATOR_ADDITION_H

#include <iostream>
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
    Operation *simplify() override{
        if (left->simplify()->isZero()) return right->simplify();
        if (right->simplify()->isZero()) return left->simplify();
        if (dynamic_cast<Constant*>(left->simplify()) && dynamic_cast<Constant*>(right->simplify()))
            return new Constant(left->simplify()->getNumber(0) + right->simplify()->getNumber(0));
        else return new Addition(left->simplify(), right->simplify());
    }
};


#endif //DERIVATIVE_CALCULATOR_ADDITION_H
