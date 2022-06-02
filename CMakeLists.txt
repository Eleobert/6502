cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(6502)

set(CMAKE_CXX_FLAGS "-g -O0")

add_subdirectory(run_rom)
add_subdirectory(test)

add_library(6502 SHARED 
    include/run.hpp 
    src/run.cpp 
    src/ops.hpp 
    include/lookup.hpp 
    src/lookup.cpp 
    include/types.hpp 
    include/utility.hpp)

target_compile_features(6502 PRIVATE cxx_std_20)
target_include_directories(6502 PUBLIC include)

enable_testing()
