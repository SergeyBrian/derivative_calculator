//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_DIVISION_H
#define DERIVATIVE_CALCULATOR_DIVISION_H
#include "BinaryOperation.h"
#include "Subtraction.h"
#include "Constant.h"
#include "Pow.h"
#include "Product.h"

class Division : public BinaryOperation{
public:
    Division(Operation *l, Operation *r) : BinaryOperation (l, r) {};
    string getString() override {
        return "\\dfrac{" + left->getString() + "}{" + right->getString() + "}";
    }
    double getNumber(double val) override {
        return left->getNumber(val)/right->getNumber(val);
    }
    Operation *getDerivative();
};


#endif //DERIVATIVE_CALCULATOR_DIVISION_H
