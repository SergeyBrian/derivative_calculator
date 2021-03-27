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
    Operation *getDerivative() override;
    Operation *simplify() override{
        if (right->simplify()->isZero() || left->simplify()->isOne()) return new Constant(1);
        if (right->simplify()->isOne()) return left->simplify();
        if (left->simplify()->isZero()) return new Constant(0);
        if (dynamic_cast<Constant*>(left->simplify()) && dynamic_cast<Constant*>(right->simplify()))
            return new Constant(pow(left->simplify()->getNumber(0), right->simplify()->getNumber(0)));
        else return new Pow(left->simplify(), right->simplify());

    }
};


#endif //DERIVATIVE_CALCULATOR_POW_H
