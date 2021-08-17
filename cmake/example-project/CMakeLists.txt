cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

set(myVar1 "Hello")
set(myVar2 "World")

configure_file(TutorialConfig.h.in TutorialConfig.h)

add_executable(Tutorial Tutorial.cpp)

target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")

