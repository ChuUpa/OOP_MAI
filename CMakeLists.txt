cmake_minimum_required(VERSION 3.10)

project(Lab3Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

include_directories(${INCLUDE_DIR})

add_executable(main_lab5 ${SOURCE_DIR}/main.cpp)

add_executable(tests_lab5 ${TEST_DIR}/test_figure.cpp)

add_library(Figures STATIC
    ${SOURCE_DIR}/Figure.cpp
    ${SOURCE_DIR}/FigureArray.cpp
    ${SOURCE_DIR}/Rectangle.cpp
    ${SOURCE_DIR}/Point.cpp
    ${SOURCE_DIR}/Rhombus.cpp
    ${SOURCE_DIR}/Trapezoid.cpp
)

target_link_libraries(main_lab5 Figures)

add_subdirectory(${CMAKE_SOURCE_DIR}/external/googletest googletest)

target_link_libraries(tests_lab5 gtest gtest_main Figures)

include(GoogleTest)
gtest_discover_tests(tests_lab5)
