//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_TAN_H
#define DERIVATIVE_CALCULATOR_TAN_H


#include "UnaryOperation.h"
#include "Division.h"
#include "Cos.h"
#include "Pow.h"
#include "Constant.h"

class Tan : public UnaryOperation {
public:
    explicit Tan(Operation *o) : UnaryOperation (o) {};
    string getString() override {
        return "\\\\tan(" + operation->getString() + ")";
    }
    double getNumber(double val) override {
        return tan(operation->getNumber(val));
    }
    Operation *getDerivative() override {
        return new Division(operation->getDerivative(), new Pow(new Cos(operation), new Constant(2)));
    }
    Operation *simplify() override{return new Tan(operation->simplify());}

};


#endif //DERIVATIVE_CALCULATOR_TAN_H
