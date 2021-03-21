//
// Created by sergio on 20.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_BINARYOPERATION_H
#define DERIVATIVE_CALCULATOR_BINARYOPERATION_H

#include "Operation.h"

class BinaryOperation : public Operation {
public:
    Operation *left;
    Operation *right;
    BinaryOperation(Operation *l, Operation *r) {
        left=l;
        right=r;
    }
};


#endif //DERIVATIVE_CALCULATOR_BINARYOPERATION_H
