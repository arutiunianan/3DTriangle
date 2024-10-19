cmake_minimum_required(VERSION 3.10)

project(triangle)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(GTest REQUIRED)

if(TEST)
    add_executable(3dtr test/unit_test.cpp triangle/triangle.cpp point/point.cpp vector/vector.cpp plane/plane.cpp line/line.cpp)
    target_include_directories(3dtr PRIVATE ${GTEST_INCLUDE_DIRS})
    target_link_libraries(3dtr GTest::GTest GTest::Main)
else()
    add_executable(3dtr main.cpp triangle/triangle.cpp point/point.cpp vector/vector.cpp plane/plane.cpp line/line.cpp)
endif()