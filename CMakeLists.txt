# Build options
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Weffc++")

add_executable(auto_ptr auto_ptr.cpp)
add_executable(unique_ptr unique_ptr.cpp)
