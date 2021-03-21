//
// Created by sergio on 20.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_OPERATION_H
#define DERIVATIVE_CALCULATOR_OPERATION_H

#include <string>

using namespace std;

class Operation {
public:
    int type_id;
    virtual double getNumber(double val);
    virtual string getString() = 0;
    virtual Operation *getDerivative() = 0;
};


#endif //DERIVATIVE_CALCULATOR_OPERATION_H
