//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_SIN_H
#define DERIVATIVE_CALCULATOR_SIN_H

#include "UnaryOperation.h"
#include "Product.h"
#include "Cos.h"

class Sin : public UnaryOperation{
public:
    explicit Sin(Operation *o) : UnaryOperation(o) {};
    string getString() override {
        return "\\sin(" + operation->getString() + ")";
    }
    double getNumber(double val) override {
        return sin(operation->getNumber(val));
    }
    Operation *getDerivative();
};


#endif //DERIVATIVE_CALCULATOR_SIN_H
