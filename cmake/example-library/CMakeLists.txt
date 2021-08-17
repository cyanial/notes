# Top-level CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(use_lib)

add_subdirectory(mymath)

add_executable(use_lib main.cpp)

target_link_libraries(use_lib PUBLIC MyMath)

target_include_directories(use_lib PUBLIC
  "${PROJECT_SOURCE_DIR}/mymath"
)


# Installing
install(TARGETS use_lib DESTINATION bin)
