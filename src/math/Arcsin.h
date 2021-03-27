//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_ARCSIN_H
#define DERIVATIVE_CALCULATOR_ARCSIN_H


#include "UnaryOperation.h"
#include "Division.h"
#include "Sqrt.h"
#include "Pow.h"


class Arcsin : public UnaryOperation{
public:
    explicit Arcsin(Operation *o) : UnaryOperation(o)  {};
    string getString() override {
        return "\\\\arcsin(" + operation->getString() + ")";
    }
    double getNumber(double val) override {
        return asin(operation->getNumber(val));
    }
    Operation *getDerivative() override {
        return new Division(operation->getDerivative(),
                            new Sqrt(new Subtraction(new Constant(1),
                                                     new Pow(operation, new Constant(2)))));
    }
    Operation *simplify() override{return new Arcsin(operation->simplify());}
};


#endif //DERIVATIVE_CALCULATOR_ARCSIN_H
