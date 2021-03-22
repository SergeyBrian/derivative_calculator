//
// Created by sergio on 22.03.2021.
//

#include "Log.h"

Operation * Log::getDerivative() {
    return new Division(operation->getDerivative(), operation);
}
