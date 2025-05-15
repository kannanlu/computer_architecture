cmake_minimum_required(VERSION 3.10)
project(cpp_explore CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find header files 
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(emulator ./emulator.cpp)