cmake_minimum_required(VERSION 3.17)
project(derivative_calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(derivative_calculator main.cpp src/math/Operation.cpp src/math/Operation.h src/math/BinaryOperation.cpp src/math/BinaryOperation.h src/math/Add.cpp src/math/Add.h src/math/UnaryOperation.cpp src/math/UnaryOperation.h src/math/Variable.cpp src/math/Variable.h src/math/Constant.cpp src/math/Constant.h src/math/Product.cpp src/math/Product.h)