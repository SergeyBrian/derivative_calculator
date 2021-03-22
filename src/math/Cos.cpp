//
// Created by sergio on 22.03.2021.
//

#include "Cos.h"

Operation * Cos::getDerivative() {
    return new Negate(new Product(new Sin(operation), operation->getDerivative()));
}
