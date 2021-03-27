//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_ARCCOS_H
#define DERIVATIVE_CALCULATOR_ARCCOS_H

#include "UnaryOperation.h"
#include "Negate.h"
#include "Division.h"
#include "Pow.h"
#include "Constant.h"
#include "Subtraction.h"
#include "Sqrt.h"

class Arccos : public UnaryOperation{
public:
    explicit Arccos(Operation *o) : UnaryOperation(o) {};
    string getString() override {
        return "\\arccos(" + operation->getString() + ")";
    }
    double getNumber(double val) override {
        return acos(operation->getNumber(val));
    }
    Operation *getDerivative() override;
    Operation *simplify() override{return new Arccos(operation->simplify());}
};


#endif //DERIVATIVE_CALCULATOR_ARCCOS_H
