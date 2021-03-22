//
// Created by sergio on 22.03.2021.
//

#include "Pow.h"

Operation * Pow::getDerivative() {
    Operation *first = new Pow(left, right);
    Operation *second = new Addition(new Product(right->getDerivative(), new Log(left)),
                                     new Division(new Product(left->getDerivative(), right), left));
    return new Product(first, second);
}
