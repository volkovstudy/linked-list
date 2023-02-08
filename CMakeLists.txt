cmake_minimum_required(VERSION 3.24)
project(linked-list)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

file(GLOB_RECURSE main-sources
        "src/linked-list/*.cpp"
)

add_executable(linked-list src/main.cpp ${main-sources})


################################
# GTest
################################
find_package(GTest REQUIRED)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


################################
# Unit Tests
################################
include_directories(tests)

set(test-sources ${main-sources})

add_executable(unit-tests ${test-sources} tests/linked-list-tests/tests.cpp)
target_link_libraries(unit-tests gtest gtest_main)

add_test(unit-tests unit-tests)
