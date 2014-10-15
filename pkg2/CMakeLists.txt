cmake_minimum_required(VERSION 2.8.7)
#include cutil
include("$ENV{CUTIL_PATH}/cmake/cutil_new.cmake")


project(pkg2)



path_component(${CMAKE_CURRENT_LIST_DIR} --parent-dir)
ans(pd)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${pd}/installed)

find_package(calcInterface REQUIRED)


include_directories(${calcInterface_DIR})
add_executable(testApp main.cpp)
target_link_libraries(testApp interface)

#print_locals()
#print_project_tree()

#print_target(testApp)
#print_target(interface)
