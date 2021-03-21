//
// Created by sergio on 21.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_PRODUCT_H
#define DERIVATIVE_CALCULATOR_PRODUCT_H
#include "BinaryOperation.h"
#include "Operation.h"
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
        return (left->type=="Constant") ? new Product(Constant(left->getNumber(0)), right->getDerivative()) :
        new Product(left->getDerivative(), right->getDerivative());
    }
};


#endif //DERIVATIVE_CALCULATOR_PRODUCT_H
