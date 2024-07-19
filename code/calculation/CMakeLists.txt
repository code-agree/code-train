cmake_minimum_required(VERSION 3.10)
project(PostfixCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Library
add_library(postfix_calculator_lib src/PostfixCalculator.cpp)

# Main executable
add_executable(postfix_calculator main/main.cpp)
target_link_libraries(postfix_calculator postfix_calculator_lib)

# Tests
enable_testing()
add_subdirectory(test)