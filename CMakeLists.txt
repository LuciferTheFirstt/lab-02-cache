cmake_minimum_required(VERSION 2.8)

project(CH CXX)

if (MSVC)
    add_definitions(/W4)
else()
    add_definitions(-Wall)
    add_definitions(-std=c++17)
endif()

include_directories(include)

enable_testing()

add_library(Lib STATIC include/Source.cpp)

add_executable(tests_Cache main.cpp)

target_link_libraries(tests_Cache Lib)

add_executable(tests include/Source.cpp)

add_test(NAME ${PROJECT_NAME} COMMAND tests_Cache)

