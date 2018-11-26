cmake_minimum_required(VERSION 3.0)
project(cpplambdas)

include(CheckIncludeFiles)

#find dependencies

add_definitions(-DCMAKE_CONFIG)


add_subdirectory(src)
