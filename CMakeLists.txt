cmake_minimum_required(VERSION 3.19)
project(tech_flow)

set(CMAKE_CXX_STANDARD 14)

string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")

# Solution library
add_library(solution STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/solution.cpp)

target_include_directories(solution PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Main
add_executable(main
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_include_directories(main PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(main
        PUBLIC solution)


