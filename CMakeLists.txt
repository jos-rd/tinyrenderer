cmake_minimum_required(VERSION 3.28)

project(tinyrenderer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Variables
set(SRC_PREFIX renderer)
set(TEST_PREFIX test)
set(SOURCES
   ${SRC_PREFIX}/main.cpp
   ${SRC_PREFIX}/tgaimage.cpp
   ${SRC_PREFIX}/tgaimage.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

# GTest
set(TESTS
   ${TEST_PREFIX}/test.cpp
)

find_package(GTest CONFIG REQUIRED)

enable_testing()
add_executable(unitTests ${TESTS})
target_link_libraries(unitTests GTest::gtest_main)

include(GoogleTest) # Load and run CMake code from a file or module.
gtest_discover_tests(unitTests)
