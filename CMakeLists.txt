cmake_minimum_required(VERSION 2.8)

# Build options
set(CMAKE_CXX_COMPILER "g++") # (g++ seems to actually do something with -Weffc++)
set(CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Weffc++")

add_executable(typetest typetest.cpp)
add_executable(auto_ptr auto_ptr.cpp)
add_executable(unique_ptr unique_ptr.cpp)
add_executable(list-initializers list-initializers.cpp)
add_executable(array-bounds array-bounds.cpp)
add_executable(accumulate accumulate.cpp)
add_executable(object-lifetime object-lifetime.cpp)
add_executable(shared_ptr shared_ptr.cpp)
add_executable(casts casts.cpp)
add_executable(classes classes.cpp)
add_executable(lvalues lvalues.cpp)
add_executable(bad_alloc bad_alloc.cpp)
add_executable(rtti rtti.cpp)
add_executable(division division.cpp)

add_executable(future future.cpp)
set_target_properties(future PROPERTIES LINK_FLAGS "-pthread")

# those are c++14:

add_executable(return-type-deduction return-type-deduction.cpp)
#XXX a bit ugly, as the -std=c++1y gets appended to the other flags, which say -std=c++11
set_source_files_properties(return-type-deduction.cpp PROPERTIES COMPILE_FLAGS "-std=c++1y")

# checks
add_custom_command(OUTPUT check-cpplint
  COMMAND find . -path ./ext -prune -or -path ./*CMakeFiles -prune -or \( -name *.cc -or -name *.cpp \) -print0 | xargs -0 cpplint
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Running cpplint" VERBATIM
)
add_custom_target(check
  DEPENDS check-cpplint
)
