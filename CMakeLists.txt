cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(ProgMathsS3 LANGUAGES C CXX)

# files to compile
add_executable(ProgMathsS3 my_examples/src/main.cpp 
			         libRatio/src/Ratio.cpp
			         my_examples/src/test1.cpp

			         libRatio/include/Ratio.hpp
			         my_examples/include/test1.hpp)

# specify the include dir
target_include_directories(ProgMathsS3 PRIVATE "include")

# vscode can't work fine without
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# (optional) add a "output" directory in the project binary directory
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/output)

# (optional) put the binary files in this directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# add my_examples
message(STATUS "my_examples cmake part ..." )
add_subdirectory(my_examples)

# compilation options
target_compile_features(ProgMathsS3 PRIVATE cxx_std_17) # use at least c++ 17
if (MSVC)
    target_compile_options(ProgMathsS3 PRIVATE /W3)
else()
    target_compile_options(ProgMathsS3 PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()