cmake_minimum_required(VERSION 3.4)

project(CH CXX)

if (MSVC)
    add_definitions(/W4)
else()
    add_definitions(-Wall)
    add_definitions(-std=c++17)
endif()

include_directories(include)

enable_testing()

add_library(Lib STATIC sources/Source.cpp)

add_executable(test_cache main.cpp)

target_link_libraries(test_cache Lib)

add_test(NAME ${PROJECT_NAME} COMMAND tests_Cache)

