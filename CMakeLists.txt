cmake_minimum_required(VERSION 3.21.0)

project(YearCalendar1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-O0 -Wall")

file(GLOB CPP_SOURCE "${PROJECT_SOURCE_DIR}/Source/*.cpp")

include_directories(${PROJECT_SOURCE_DIR}/Header)

add_executable(${PROJECT_NAME} ${CPP_SOURCE})

add_library(YearCalendarFcts SHARED Source/year_calendar_functs.cpp)