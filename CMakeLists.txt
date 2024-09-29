cmake_minimum_required(VERSION 3.10)

project(triangle)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(3dtriangle main.cpp triangle/triangle.cpp point/point.cpp plane/plane.cpp line/line.cpp)
target_include_directories(3dtriangle PRIVATE main.cpp triangle point&vector plane line)

if(TEST)
    target_compile_definitions(3dtriangle PRIVATE TEST=1)
endif()