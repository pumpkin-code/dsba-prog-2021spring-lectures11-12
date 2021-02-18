cmake_minimum_required(VERSION 3.0)

project(Lectures_11_12_Demos CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 14)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

#### the list of targets ####
add_executable(ex1_sets ex1_sets/main.cpp)
add_executable(ex2_hashset ex2_hashset/main.cpp)
add_executable(ex3 ex3/main.cpp)
add_executable(ex4_maps ex4_maps/main.cpp)
