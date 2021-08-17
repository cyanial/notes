# mymath/CMakeLists.txt

add_library(MyMath mymath.cpp)

# Re-factor
target_include_directories(MyMath 
  INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}"
)

# `INTERFACE` means things that consumers require but the producer doesn't.


# Installing
install(TARGETS MyMath DESTINATION lib)
install(FILES mymath.h DESTINATION include)

## install(DIRECTORIES include ...)