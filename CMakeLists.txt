cmake_minimum_required(VERSION 3.10)

project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Leetcode main.cpp config.h
        Leetcode893cn/Leetcode893cn.cpp Leetcode893cn/Leetcode893cn.h
        Leetcode896cn/Leetcode896cn.cpp Leetcode896cn/Leetcode896cn.h
        Leetcode897cn/Leetcode897cn.cpp Leetcode897cn/Leetcode897cn.h)


