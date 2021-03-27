//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_EXP_H
#define DERIVATIVE_CALCULATOR_EXP_H
#include "UnaryOperation.h"
#include "Product.h"

class Exp : public UnaryOperation {
public:
    explicit Exp(Operation *o) : UnaryOperation(o) {};
    string getString() override {
        return "e^{" + operation->getString() + "}";
    }
    double getNumber(double val) override {
        return exp(operation->getNumber(val));
    }
    Operation *getDerivative() override {
        return new Product(new Exp(operation), operation->getDerivative());
    }
    Operation *simplify() override{return new Exp(operation->simplify());}
};


#endif //DERIVATIVE_CALCULATOR_EXP_H
