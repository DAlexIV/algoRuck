cmake_minimum_required(VERSION 3.3)
project(rrrrrr)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp rucksack.h in_params.cpp in_params.h out_params.cpp out_params.h)
add_executable(rrrrrr ${SOURCE_FILES})