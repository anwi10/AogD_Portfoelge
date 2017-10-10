cmake_minimum_required(VERSION 3.6)
project(BallsAndBins)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BallsAndBins.cpp BallsAndBins.h BinarySearchTree.cpp)
add_executable(BallsAndBins ${SOURCE_FILES})