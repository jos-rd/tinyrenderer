cmake_minimum_required(VERSION 3.28)

project(tinyrenderer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(renderer)
add_subdirectory(test)

enable_testing()