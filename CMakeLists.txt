cmake_minimum_required(VERSION 3.21.0)

project(YearCalendarV1)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-O3 -Wall")

file(GLOB CPP_SOURCE "${PROJECT_SOURCE_DIR}/Source/*.cpp")

include_directories(${PROJECT_SOURCE_DIR}/Header)

add_executable(${PROJECT_NAME} ${CPP_SOURCE})