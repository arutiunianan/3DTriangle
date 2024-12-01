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
    add_definitions(-DCMAKE_CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

    add_executable(test test/unit_test.cpp triangle/triangle.cpp triangle/intersection.cpp octree/octree.cpp point/point.cpp vector/vector.cpp plane/plane.cpp line/line.cpp)
    target_include_directories(test PRIVATE ${GTEST_INCLUDE_DIRS})
    target_link_libraries(test GTest::GTest GTest::Main)
else()
    add_executable(3dtr main.cpp triangle/triangle.cpp triangle/intersection.cpp octree/octree.cpp point/point.cpp vector/vector.cpp plane/plane.cpp line/line.cpp)
endif()