cmake_minimum_required(VERSION 3.16.3)

project(TestSTC_1)

add_library(add SHARED Parser/Parser.cpp)
target_include_directories(add PUBLIC Parser/inc)

add_executable(a.out Source/main.cpp)
#target_include_directories(a.out PUBLIC Source)

target_link_libraries(a.out add)
target_include_directories(a.out PUBLIC Parser/inc)