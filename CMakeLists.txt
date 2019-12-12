cmake_minimum_required(VERSION 3.10)

project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Leetcode main.cpp config.h
        Leetcode844cn/Leetcode844cn.cpp Leetcode844cn/Leetcode844cn.h
        Leetcode849cn/Leetcode849cn.cpp Leetcode849cn/Leetcode849cn.h
        Leetcode852cn/Leetcode852cn.cpp Leetcode852cn/Leetcode852cn.h
        Leetcode860cn/Leetcode860cn.cpp Leetcode860cn/Leetcode860cn.h
        Leetcode867cn/Leetcode867cn.cpp Leetcode867cn/Leetcode867cn.h)

