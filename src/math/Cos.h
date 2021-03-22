//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_COS_H
#define DERIVATIVE_CALCULATOR_COS_H

#include "UnaryOperation.h"
#include "Sin.h"
#include "Negate.h"
#include "Product.h"

class Cos : public UnaryOperation{
public:
    explicit Cos(Operation *o) : UnaryOperation (o) {};
    string getString() override {
        return "\\cos(" + operation->getString() + ")";
    }
    double getNumber(double val) override {
        return cos(operation->getNumber(val));
    }
    Operation *getDerivative();
};


#endif //DERIVATIVE_CALCULATOR_COS_H
