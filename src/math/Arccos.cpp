//
// Created by sergio on 22.03.2021.
//

#include "Arccos.h"

Operation *Arccos::getDerivative() {
    return new Negate(new Division(operation->getDerivative(),
                                   new Sqrt(new Subtraction(new Constant(1),
                                                            new Pow(operation, new Constant(2))))));
}
