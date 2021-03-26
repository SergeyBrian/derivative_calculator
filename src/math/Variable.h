//
// Created by sergio on 20.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_VARIABLE_H
#define DERIVATIVE_CALCULATOR_VARIABLE_H

#include "Operation.h"
#include "Constant.h"

class Variable : public Operation {
public:
    string getString() override{return "x";}
    double getNumber(double val) override{return val;}
    Operation* getDerivative()  override{return new Constant(1);}
};


#endif //DERIVATIVE_CALCULATOR_VARIABLE_H
