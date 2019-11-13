cmake_minimum_required(VERSION 3.15)
project(for_trying_random_stuff)

set(CMAKE_CXX_STANDARD 17)
add_definitions(-DLOCAL)
add_executable(for_trying_random_stuff test_gen.cpp)