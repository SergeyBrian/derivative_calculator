//
// Created by sergio on 21.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_PRODUCT_H
#define DERIVATIVE_CALCULATOR_PRODUCT_H
#include "BinaryOperation.h"
#include "Operation.h"
#include "Addition.h"
#include "Constant.h"

class Product : public BinaryOperation {
public:
    Product(Operation *l, Operation *r) : BinaryOperation(l, r) {};
    string getString() override {
        return "(" + left->getString() + ") \\cdot (" + right->getString() + ")";
    }
    double getNumber(double val) override {
        return left->getNumber(val)*right->getNumber(val);
    }
    Operation *getDerivative() override {
        return  new Addition(new Product(left, right->getDerivative()), new Product(left->getDerivative(), right));
    }
    Operation *simplify() override{
        if (left->simplify()->isZero() || right->simplify()->isZero()) return new Constant(0);
        if (left->simplify()->isOne()) return right->simplify();
        if (right->simplify()->isOne()) return left->simplify();
        if (dynamic_cast<Constant*>(left->simplify()) && dynamic_cast<Constant*>(right->simplify()))
            return new Constant(left->simplify()->getNumber(0) * right->simplify()->getNumber(0));
        else return new Product(left->simplify(), right->simplify());

    }
};


#endif //DERIVATIVE_CALCULATOR_PRODUCT_H
