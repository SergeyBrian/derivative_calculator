//
// Created by sergio on 20.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_OPERATION_H
#define DERIVATIVE_CALCULATOR_OPERATION_H

#include <string>

using namespace std;

class Operation {
    virtual double getNumber(double val);
    virtual string getString(double val);
    virtual Operation getDerivative();
};


#endif //DERIVATIVE_CALCULATOR_OPERATION_H
