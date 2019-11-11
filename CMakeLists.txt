cmake_minimum_required(VERSION 3.10)

project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Leetcode main.cpp config.h
        Leetcode236cn/Leetcode236cn.cpp Leetcode236cn/Leetcode236cn.h Leetcode142cn/Leetcode142cn.cpp Leetcode142cn/Leetcode142cn.h)

