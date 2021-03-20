//
// Created by sergio on 20.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_BINARYOPERATION_H
#define DERIVATIVE_CALCULATOR_BINARYOPERATION_H

#include <string>
#include "Operation.h"
using namespace std;
class BinaryOperation {
    virtual double getNumber(Operation left, Operation right);
    virtual string getString(Operation left, Operation right);
    virtual Operation getDerivative(Operation left, Operation right);
};


#endif //DERIVATIVE_CALCULATOR_BINARYOPERATION_H
