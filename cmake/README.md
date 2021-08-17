# CMake Notes

- [CMake Notes](#cmake-notes)
  - [Basic Start](#basic-start)
    - [Install CMake & ninja-build (MacOS)](#install-cmake--ninja-build-macos)
    - [Basic structure](#basic-structure)
    - [Access variable in CMake](#access-variable-in-cmake)
    - [Set up the C++ Standard](#set-up-the-c-standard)
    - [Out-of-source build](#out-of-source-build)

## Basic Start 

### Install CMake & ninja-build (MacOS)

```sh
$ brew install cmake
$ brew install ninja
$ cmake --version
cmake version 3.21.1

$ ninja --version
1.10.2

```

### Basic structure

```cmake
# Top-level CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

# add the executable
add_executable(Tutorial tutorial.cpp)
```

### Access variable in CMake

Set up a config header file `TutorialConfig.h.in` to generate `TutorialConfig.h`.

```cmake
# Configured Header
cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

set(myVar1 "Hello")
set(myVar2 "World")

configure_file(TutorialConfig.h.in TutorialConfig.h)

add_executable(Tutorial Tutorial.cpp)

target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")
```

```cpp
// TutorialConfig.h.in
#ifndef __TUTORIALCONFIG_H__
#define __TUTORIALCONFIG_H__

#define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
#define Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@

#define My_Var_1 "@myVar1@"
#define My_Var_2 "${myVar2}"

#endif // __TUTORIALCONFIG_H__
```

### Set up the C++ Standard

Set the CMake Variable `CMAKE_C_STANDARD` and `CMAKE_CXX_STANDARD` to speficy a C/C++ standard. Variable `CMAKE_CXX_STANDARD_REQUIRED` makes sure that the standard must required.

```cmake
# set standard
cmake_minimum_required(VERSION 3.10)
project(Tutorial)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add_executable
```

### Out-of-source build

Seperate the source file and the build output to better organize the project.

```sh
$ cmake -S . -B build [-G Ninja] 
$ cmake --build build
```

