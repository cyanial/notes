cmake_minimum_required(VERSION 3.10)

project(example-prevar)

message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS ${CMAKE_BINARY_DIR})
message(STATUS ${CMAKE_SOURCE_DIR})
message(STATUS ${example-prevar_BINARY_DIR})
message(STATUS ${example-prevar_SOURCE_DIR})
message(STATUS ${PROJECT_BINARY_DIR})
message(STATUS ${PROJECT_SOURCE_DIR})

add_executable(example-prevar main.cpp)