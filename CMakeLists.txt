cmake_minimum_required(VERSION 3.10)

project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Leetcode main.cpp config.h Leetcode92cn/Leetcode92cn.cpp Leetcode92cn/Leetcode92cn.h)
