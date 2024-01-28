cmake_minimum_required(VERSION 3.28)

set(TESTS
rasterisationTests.cpp
)

find_package(GTest CONFIG REQUIRED)
add_executable(rendererTests ${TESTS})
target_include_directories(rendererTests PRIVATE ${CMAKE_SOURCE_DIR}/renderer)
target_link_libraries(rendererTests GTest::gtest_main rendererLib)

include(GoogleTest)
gtest_discover_tests(rendererTests)