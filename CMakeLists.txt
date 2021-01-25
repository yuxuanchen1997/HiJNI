cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

if (NOT DEFINED LLVM_BIN)
  message(FATAL_ERROR "Please set \"-DLLVM_BIN=/some/path\" with clang, llvm-link, llvm-dis etc")
endif()

set(CMAKE_CXX_COMPILER ${LLVM_BIN}/clang++)

project(main CXX)

find_package(JNI REQUIRED)
find_package(Java REQUIRED)
include(UseJava)

include_directories(include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(lib)
