//
// Created by sergio on 22.03.2021.
//

#include "Division.h"

Operation * Division::getDerivative() {
    return new Division(new Subtraction(
            new Product(right, left->getDerivative()),
            new Product(right->getDerivative(), left)),
                        new Pow(right, new Constant(2)));
}
