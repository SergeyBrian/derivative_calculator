//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_SQRT_H
#define DERIVATIVE_CALCULATOR_SQRT_H

#include "UnaryOperation.h"
#include "Division.h"
#include "Product.h"
#include "Constant.h"

class Sqrt : public UnaryOperation{
public:
    explicit Sqrt(Operation *o) : UnaryOperation(o) {};
    string getString() override {
        return "\\sqrt{" + operation->getString() + "}";
    }
    double getNumber(double val) override {
        return sqrt(operation->getNumber(val));
    }
    Operation *getDerivative() override {
        return new Division(operation->getDerivative(),
                            new Product(new Constant(2), new Sqrt(operation)));
    }
};


#endif //DERIVATIVE_CALCULATOR_SQRT_H
