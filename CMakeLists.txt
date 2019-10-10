cmake_minimum_required(VERSION 3.10)

project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Leetcode main.cpp config.h Leetcode23cn/Leetcode23cn.cpp Leetcode23cn/Leetcode23cn.h Leetcode16cn/Leetcode16cn.cpp Leetcode16cn/Leetcode16cn.h Leetcode43cn/Leetcode43cn.cpp Leetcode43cn/Leetcode43cn.h)
