//
// Created by sergio on 20.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_CONSTANT_H
#define DERIVATIVE_CALCULATOR_CONSTANT_H

#include "Operation.h"

class Constant : public Operation {
private:
    double value;
public:
    explicit Constant(double val) {
        value = val;
    }
    double getNumber(double val) override {return value;}
    string getString() override {return "c";}
    Operation* getDerivative() override{
        return new Constant(0);
    }
};


#endif //DERIVATIVE_CALCULATOR_CONSTANT_H
