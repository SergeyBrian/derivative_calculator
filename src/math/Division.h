//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_DIVISION_H
#define DERIVATIVE_CALCULATOR_DIVISION_H
#include "BinaryOperation.h"
#include "Subtraction.h"
#include "Constant.h"
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
    Operation *getDerivative() override;
    Operation *simplify() override{
        if (left->simplify()->isZero()) return new Constant(0);
        if (right->simplify()->isOne()) return left->simplify();
        if (dynamic_cast<Constant*>(left->simplify()) && dynamic_cast<Constant*>(right->simplify()))
            return new Constant(left->simplify()->getNumber(0) / right->simplify()->getNumber(0));
        else return new Division(left->simplify(), right->simplify());

    }
};


#endif //DERIVATIVE_CALCULATOR_DIVISION_H
