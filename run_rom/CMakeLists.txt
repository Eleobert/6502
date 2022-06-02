cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(run_rom)

find_package(fmt)

set(CMAKE_CXX_FLAGS "-g -O0")
add_executable(run_rom main.cpp)
target_compile_features(run_rom PRIVATE cxx_std_20)
target_link_libraries(run_rom fmt::fmt 6502)
