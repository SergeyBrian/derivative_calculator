//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_ATAN_H
#define DERIVATIVE_CALCULATOR_ATAN_H

#include "UnaryOperation.h"
#include "Division.h"
#include "Addition.h"
#include "Constant.h"
#include "Cos.h"
#include "Pow.h"

class Atan : public UnaryOperation{
public:
    explicit Atan(Operation *o) : UnaryOperation(o) {};
    string getString() override {
        return "\\arctan(" + operation->getString() + ")";
    }
    double getNumber(double val) override {
        return atan(operation->getNumber(val));
    }
    Operation *getDerivative() override {
        return new Division(operation->getDerivative(),
                            new Addition(new Constant(1),
                                         new Pow(new Cos(operation), new Constant(2))));
    }
    Operation *simplify() override{return new Atan(operation->simplify());}
};


#endif //DERIVATIVE_CALCULATOR_ATAN_H
