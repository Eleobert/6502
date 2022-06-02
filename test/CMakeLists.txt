cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(test_6502)

find_package(GTest)

add_executable(test_6502 test.cpp)
target_compile_features(test_6502 PRIVATE cxx_std_20)
target_link_libraries(test_6502 6502 GTest::gtest)

add_test(NAME test_6502 COMMAND test_6502)