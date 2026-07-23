cmake_minimum_required(VERSION 3.14)
project(PointCloudTriangulation VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_executable(triangulator src/main.cpp)

add_executable(test_runner tests/test_placeholder.cpp)
add_test(NAME PlaceholderTest COMMAND test_runner)