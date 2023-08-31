cmake_minimum_required(VERSION 3.21)
project(oj_solutions)

set(CMAKE_CXX_STANDARD 11)
add_definitions(-DLOCAL)

file(GLOB CPPS ${CMAKE_CURRENT_LIST_DIR}/*/*.cpp)
foreach(cpp ${CPPS})
    get_filename_component(target ${cpp} NAME_WE)
    add_executable(${target} ${cpp})
endforeach()

add_executable(answer answer.cpp)
