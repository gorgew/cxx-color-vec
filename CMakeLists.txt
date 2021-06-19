##This is a CMakeList for running tests

cmake_minimum_required(VERSION 3.19)
set(VCPKG_FEATURE_FLAGS "versions")
project(color-vec VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wextra -Wno-unused-parameter -Wsequence-point")
    message(STATUS "Compiler: GNU/CLANG")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
    set(CMAKE_GENERATOR_PLATFORM x64)
    set(CMAKE_GENERATOR_PLATFORM win32)
    message(STATUS "Compiler: MSVC")
else()
    message(STATUS "Compiler: Unsupported")
endif()

add_subdirectory(src)
add_subdirectory(test)