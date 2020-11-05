cmake_minimum_required(VERSION 3.0)
project(cpplambdas)

set(CMAKE_CXX_STANDARD 17)

include(CheckIncludeFiles)

#find dependencies

add_definitions(-DCMAKE_CONFIG)


add_subdirectory(src)
