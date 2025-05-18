cmake_minimum_required(VERSION 3.21.0)

project(YearCalendar)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-O0 -Wall")

file(GLOB CC_SOURCE "${PROJECT_SOURCE_DIR}/Source/*.cc")

include_directories(${PROJECT_SOURCE_DIR}/Header)

add_executable(${PROJECT_NAME} ${CC_SOURCE})