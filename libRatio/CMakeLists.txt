cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(ProgMathsS3 LANGUAGES C CXX)

# automatic get all files in a directory
file(GLOB_RECURSE source_files src/*.cpp)
file(GLOB_RECURSE header_files include/*.hpp)

#lib ratio compilation
add_library(Ratio ${source_files} ${header_files})

# compilation flags
target_compile_features(Ratio PRIVATE cxx_std_17) # use at least c++ 17
if (MSVC)
    target_compile_options(Ratio PRIVATE /W3)
else()
    target_compile_options(Ratio PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

# include directory
target_include_directories(Ratio PRIVATE "include")