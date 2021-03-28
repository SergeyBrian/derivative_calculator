//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_SUBTRACTION_H
#define DERIVATIVE_CALCULATOR_SUBTRACTION_H
#include "BinaryOperation.h"
#include "Negate.h"

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
    Operation *simplify() override{
        if (left->simplify()->isZero()) {
            Operation * r = new Negate(right->simplify());
            return r->simplify();
        }
        if (right->simplify()->isZero()) return left->simplify();
        if (dynamic_cast<Constant*>(left->simplify()) && dynamic_cast<Constant*>(right->simplify()))
            return new Constant(left->simplify()->getNumber(0) - right->simplify()->getNumber(0));
        else return new Subtraction(left->simplify(), right->simplify());

    }
};


#endif //DERIVATIVE_CALCULATOR_SUBTRACTION_H
