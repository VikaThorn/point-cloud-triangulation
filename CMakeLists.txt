cmake_minimum_required(VERSION 3.14)
project(PointCloudTriangulation VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

add_executable(triangulator 
    src/main.cpp
    src/file_parser.cpp
    src/config.cpp
    src/preprocessor.cpp
)

target_link_libraries(triangulator PRIVATE nlohmann_json::nlohmann_json)

enable_testing()
add_executable(test_runner tests/test_placeholder.cpp)
add_test(NAME PlaceholderTest COMMAND test_runner)