//
// Created by sergio on 22.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_LOG_H
#define DERIVATIVE_CALCULATOR_LOG_H

#include "UnaryOperation.h"
#include "Division.h"

class Log : public UnaryOperation{
public:
    explicit Log(Operation *o) : UnaryOperation(o) {};
    string getString() override {
        return "\\\\ln{(" + operation->getString() + ")}";
    }
    double getNumber(double val) override {
        return log(operation->getNumber(val));
    }
    Operation *getDerivative();
    Operation *simplify() override{return new Log(operation->simplify());}

};


#endif //DERIVATIVE_CALCULATOR_LOG_H
