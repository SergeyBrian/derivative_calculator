//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_NEGATE_H
#define DERIVATIVE_CALCULATOR_NEGATE_H
#include "UnaryOperation.h"
#include "Constant.h"

class Negate : public UnaryOperation{
public:
    explicit Negate(Operation *o) : UnaryOperation(o) {};
    string getString() override {
        return "-(" + operation->getString() + ")";
    }
    double getNumber(double val) override {
        return -1*operation->getNumber(val);
    }
    Operation *getDerivative() override {
        return new Negate(operation->getDerivative());
    }
    Operation *simplify() override{
        if (operation->simplify()->isZero()) return new Constant(0);
        return new Negate(operation->simplify());
    }

};


#endif //DERIVATIVE_CALCULATOR_NEGATE_H
