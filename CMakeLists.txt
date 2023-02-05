cmake_minimum_required(VERSION 3.24)
project(linked-list)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

file(GLOB_RECURSE main-sources
        "src/linked-list/*.cpp"
)

add_executable(linked-list src/main.cpp ${main-sources})

# Testing
enable_testing()

include_directories(tests)

set(test-sources ${main-sources})

# LinkedList
add_executable(linked-list-tests ${test-sources} tests/linked-list-tests/LinkedListTests.cpp)
add_test(NAME LinkedList COMMAND linked-list-tests)
