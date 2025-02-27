cmake_minimum_required(VERSION 3.10)
project(cpp_explore CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find header files 
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#add_executable(int_explore ./int_explore.cpp)
#add_executable(size_explore ./size_explore.cpp)
add_executable(array_explore ./array_explore.cpp)