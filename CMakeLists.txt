cmake_minimum_required(VERSION 3.16)
project(julienne)
set(CMAKE_CXX_FLAGS "-O2")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
link_directories(/usr/local/lib)
include_directories(src/include/)
include_directories(src/thrift/)
file(GLOB_RECURSE ALL_OBJECT_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_subdirectory(test)
add_subdirectory(third_party/googletest)
add_library(julienne_files STATIC ${ALL_OBJECT_FILES})

add_executable(julienne src/main.cpp)

target_link_libraries(julienne julienne_files pthread -lthrift)

