cmake_minimum_required(VERSION 3.26)
project(DatastructureAndAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_library(DatastructureAndAlgorithm library.cpp
        LinearList/DyLinearList.cpp
        LinearList/DyLinearList.h)
