//
// Created by sergio on 20.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_UNARYOPERATION_H
#define DERIVATIVE_CALCULATOR_UNARYOPERATION_H
#include "Operation.h"

class UnaryOperation : public Operation{
public:
    Operation *operation;
    explicit UnaryOperation(Operation *op) {operation = op;}
};


#endif //DERIVATIVE_CALCULATOR_UNARYOPERATION_H
