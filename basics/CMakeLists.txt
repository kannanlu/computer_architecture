cmake_minimum_required(VERSION 3.10)
project(cpp_explore CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find header files 
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#add_executable(int_explore ./int_explore.cpp)
#add_executable(size_explore ./size_explore.cpp)
# add_executable(array_explore ./array_explore.cpp)
# add_executable(memory_explore ./memory_explore.cpp)
# add_executable(debugger_example ./debugger_example.cpp)
# add_executable(pointer_explore ./pointer_explore.cpp)
# add_executable(cctype_explore ./cctype_explore.cpp)
# add_executable(string_explore ./string_explore.cpp)
# add_executable(reference_explore ./reference_explore.cpp)
add_executable(class_explore ./class_explore.cpp)