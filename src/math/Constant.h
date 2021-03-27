//
// Created by sergio on 20.03.2021.
//

#ifndef DERIVATIVE_CALCULATOR_CONSTANT_H
#define DERIVATIVE_CALCULATOR_CONSTANT_H

#include "Operation.h"

class Constant : public Operation {
private:
    double value;
public:
    explicit Constant(double val) {
        value = val;
    }
    double getNumber(double val) override {return value;}
    string getString() override {
        string str = std::to_string(value);
        str.erase (str.find_last_not_of('0') + 1, std::string::npos );
        return str.erase (str.find_last_not_of('.') + 1, std::string::npos );
    }
    Operation* getDerivative() override{return new Constant(0);}
    Operation* simplify() override{return new Constant(value);}
    bool isZero() override{return value==0;}
    bool isOne() override{return value==1;}
};


#endif //DERIVATIVE_CALCULATOR_CONSTANT_H
