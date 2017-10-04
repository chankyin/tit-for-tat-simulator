cmake_minimum_required(VERSION 3.8)
project(TitForTat)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Strategy.cpp Strategy.h strategies/AlwaysDefectStrategy.cpp strategies/AlwaysDefectStrategy.h strategies/AlwaysCooperateStrategy.cpp strategies/AlwaysCooperateStrategy.h GamePair.cpp GamePair.h PayoffMatrix.h strategies/TitForTatStrategy.cpp strategies/TitForTatStrategy.h)
add_executable(TitForTat ${SOURCE_FILES})
