cmake_minimum_required(VERSION 3.10)
project(StudentManager)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SRC_FILES
    src/*.cpp
)

add_executable(StudentManager ${SRC_FILES})