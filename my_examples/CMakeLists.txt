cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(MyExamples)

# file to compile and name of the executable
add_executable(MyExamples src/main.cpp src/test1.cpp include/test1.hpp)

# include directory
#target_include_directories(MyExamples PRIVATE "include")

target_link_libraries(MyExamples Ratio)

# compilation options
target_compile_features(MyExamples PRIVATE cxx_std_17) # use at least c++ 11
if (MSVC)
    target_compile_options(MyExamples PRIVATE /W3)
else()
    target_compile_options(MyExamples PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()
