cmake_minimum_required(VERSION 3.13)


enable_testing()

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(unit_tests src/test.cpp)
target_link_libraries(unit_tests PUBLIC Ratio GTest::GTest GTest::Main)
target_compile_features(unit_tests PRIVATE cxx_std_17)

gtest_discover_tests(unit_tests)