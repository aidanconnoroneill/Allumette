
include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/test/include)
# include_directories(${PROJECT_SOURCE_DIR}/third_party/googletest/googletest/include ${PROJECT_SOURCE_DIR}/third_party/googletest/)
set(CMAKE_BUILD_TYPE Debug)
add_executable(test basic_test.cpp join_test.cpp csv_loader_test.cpp table_partition_test.cpp planner_test.cpp synchronization_test.cpp scheduler_test.cpp sipi_planner_test.cpp sipi_scheduler_test.cpp)
target_link_libraries(test gtest gtest_main pthread julienne_files)