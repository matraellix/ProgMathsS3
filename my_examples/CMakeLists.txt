cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(My_Examples LANGUAGES C CXX)

# file to compile and name of the executable
add_executable(My_Examples src/main.cpp src/test1.cpp include/test1.hpp)

# include directory
target_include_directories(My_Examples PRIVATE "include")

# compilation options
target_compile_features(My_Examples PRIVATE cxx_std_17) # use at least c++ 17
if (MSVC)
    target_compile_options(My_Examples PRIVATE /W3)
else()
    target_compile_options(My_Examples PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()
