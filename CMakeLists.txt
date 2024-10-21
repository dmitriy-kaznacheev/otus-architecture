cmake_minimum_required(VERSION 3.16)
project(OtusArch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(extern/googletest)
enable_testing()

add_subdirectory(hw01-unit-tests)
add_subdirectory(hw02-abstraction)
