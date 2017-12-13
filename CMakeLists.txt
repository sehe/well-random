cmake_minimum_required (VERSION 2.8)
project (test_well_random)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR (CMAKE_C_COMPILER_ID MATCHES "Clang") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang") )
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic")
endif()

include_directories(${CMAKE_SOURCE_DIR})
add_executable (${PROJECT_NAME} main.cpp)
