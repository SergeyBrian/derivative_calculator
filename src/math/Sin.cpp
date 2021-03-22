//
// Created by sergio on 22.03.2021.
//

#include "Sin.h"

Operation * Sin::getDerivative() {
    return new Product(new Cos(operation), operation->getDerivative());
}
