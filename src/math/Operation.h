//
// Created by sergio on 20.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_OPERATION_H
#define DERIVATIVE_CALCULATOR_OPERATION_H

#include <string>
#include <cmath>

using namespace std;

class Operation {
public:
    virtual bool isZero() {return false;}
    virtual bool isOne() {return false;}
    virtual double getNumber(double val);
    virtual string getString() = 0;
    virtual Operation *getDerivative() = 0;
    virtual Operation *simplify() = 0;
};

#endif //DERIVATIVE_CALCULATOR_OPERATION_H
