cmake_minimum_required(VERSION 3.17)
project(derivative_calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(derivative_calculator main.cpp src/math/Operation.cpp src/math/Operation.h src/math/BinaryOperation.cpp src/math/BinaryOperation.h src/math/Addition.cpp src/math/Addition.h src/math/UnaryOperation.cpp src/math/UnaryOperation.h src/math/Variable.cpp src/math/Variable.h src/math/Constant.cpp src/math/Constant.h src/math/Product.cpp src/math/Product.h src/math/Pow.cpp src/math/Pow.h src/math/Division.cpp src/math/Division.h src/math/Subtraction.cpp src/math/Subtraction.h src/math/Sin.cpp src/math/Sin.h src/math/Cos.cpp src/math/Cos.h src/math/Negate.cpp src/math/Negate.h src/math/Sqrt.cpp src/math/Sqrt.h src/math/Atan.cpp src/math/Atan.h src/math/Exp.cpp src/math/Exp.h src/math/Log.cpp src/math/Log.h src/math/Arcsin.cpp src/math/Arcsin.h src/math/Tan.cpp src/math/Tan.h)