cmake_minimum_required(VERSION 3.27)
project(PA3)

set(CMAKE_CXX_STANDARD 17)

add_executable(PA3 pa3.cpp
        dataset.h
        datapoint.h
        dataset.cpp
        datapoint.cpp
        node.cpp
        node.h)
