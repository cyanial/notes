# CMake Notes

- [CMake Notes](#cmake-notes)
  - [Basic Start](#basic-start)
    - [Install CMake & ninja-build (MacOS)](#install-cmake--ninja-build-macos)
    - [Basic structure](#basic-structure)
    - [Access variable in CMake](#access-variable-in-cmake)
    - [Set up the C++ Standard](#set-up-the-c-standard)
    - [Out-of-source build](#out-of-source-build)
    - [Run a cmake script](#run-a-cmake-script)
  - [Linking libraries](#linking-libraries)
  - [Installing](#installing)
  - [Cached Variable](#cached-variable)
  - [Build Types](#build-types)

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

### Run a cmake script

Suppose we have a cmake script called `example.cmake`.

```cmake
# example.cmake
set(MY_VARIABLE "I am a variable")

message(STATUS "${MY_VARIABLE}")
```

To run it we can use following command:

```sh
$ cmake -P example.cmake
```

## Linking libraries

Suppose we have a sub directory called `mymath` which contains my self-defined math lib and a sub-dir `CMakeLists.txt`. 

Libraries are built with `STATIC` by default.

```cmake
# mymath/CMakeLists.txt

add_library(MyMath mymath.cpp)
```

```cmake
# Top-level CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(use_lib)

add_subdirectory(mymath)

add_executable(use_lib main.cpp)

target_link_libraries(use_lib PUBLIC MyMath)

target_include_directories(use_lib PUBLIC
  "${PROJECT_SOURCE_DIR}/mymath"
)
```


## Installing

Install destination will be combined with `CMAKE_INSTALL_PREFIX`.

```cmake
install(TARGETS MyMath DESTINATION lib)
install(FILES mymath.h DESTINATION include)
```

If we organize our source code with `include` lib. We can set that:

```cmake
install(DIRECTORES my_include DESTINATION include)
```

We can build with `CMAKE_INSTALL_PREFIX` to specify a install prefix: (default: `/usr/local`)

```cmake
$ cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/opt
```

Or we can specify a prefix at install time:

```cmake
$ cmake --install . --prefix "/home/myuser/installdir"
```

## Cached Variable


## Build Types

Set the variable `CMAKE_BUILD_TYPE` from `Release`, `Debug` or ...

| CMAKE_BUILD_TYPE | Compiler Setting |
| ---------------- | ---------------- |
| Release          | -O3 -DNDEBUG     |
| Debug            | -g               |
| MinSizeRel       | -Os -DNDEBUG     |
| RelWithDebInfo   | -O2 -g -DNDEBUG  |