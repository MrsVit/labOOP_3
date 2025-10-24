cmake_minimum_required(VERSION 3.14)
project(lab2_v3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(lab2_v3_lib
    figure.h
    5-squere.cpp
    array.cpp
    6-squere.cpp
    rhombus.cpp
    dot.cpp
)

target_include_directories(lab2_v3_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

add_executable(lab2_v3_exe main.cpp)
target_link_libraries(lab2_v3_exe PRIVATE lab2_v3_lib)

add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE lab2_v3_lib gtest_main)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
add_test(NAME MyProjectTests COMMAND tests)