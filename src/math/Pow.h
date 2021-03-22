//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_POW_H
#define DERIVATIVE_CALCULATOR_POW_H
#include <cmath>

#include "BinaryOperation.h"
#include "Product.h"
#include "Constant.h"
#include "Addition.h"
#include "Log.h"
#include "Division.h"

class Pow : public BinaryOperation {
public:
    Pow(Operation *l, Operation *r) : BinaryOperation(l, r) {};
    string getString() override {
        return "(" + left->getString() + ") ^ {" + right->getString() + "}";
    }
    double getNumber(double val) override {
        return pow(left->getNumber(val), right->getNumber(val));
    }
    Operation *getDerivative();
};


#endif //DERIVATIVE_CALCULATOR_POW_H
