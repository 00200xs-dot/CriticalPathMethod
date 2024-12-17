cmake_minimum_required(VERSION 3.30)
project(CriticalPathMethod C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

set(SOURCES
        src/main.c
        src/core/sort.c
        src/core/find.c
        src/core/graph.c
)

add_executable(CriticalPathMethod ${SOURCES})
