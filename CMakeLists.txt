cmake_minimum_required(VERSION 3.3)
project(rrrrrr)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp header.h source.cpp source.h source.cpp source.h in_params.cpp in_params.h out_params.cpp out_params.h)
add_executable(rrrrrr ${SOURCE_FILES})