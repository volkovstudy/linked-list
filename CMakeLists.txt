cmake_minimum_required(VERSION 3.24)
project(linked-list)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

file(GLOB_RECURSE main-sources
        "src/*.cpp"
)

add_executable(linked-list src/main.cpp ${main-sources})
