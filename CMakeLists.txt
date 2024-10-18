cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
    "googletest"
)

set(
    TEST_SOURCES
    test/test_main.cpp
    test/test_lab_2.cpp
    src/Vector.cpp
    include/Vector.hpp
    src/Ternary.cpp
    include/Ternary.hpp
)

add_executable(
    lab_2_tests
    ${TEST_SOURCES}
)

target_include_directories(
    lab_2_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
)

target_link_libraries(
    lab_2_tests
    gtest 
    gtest_main
)

enable_testing()

add_test(NAME TernaryTests COMMAND lab_2_tests)
