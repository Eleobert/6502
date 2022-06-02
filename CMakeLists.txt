cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(6502)

find_package(fmt)

set(CMAKE_CXX_FLAGS "-g -O0")
add_executable(6502 src/main.cpp src/ops.hpp src/lookup.hpp src/lookup.cpp src/types.hpp 
    src/utility.hpp)
target_compile_features(6502 PRIVATE cxx_std_20)
target_link_libraries(6502 fmt::fmt)
