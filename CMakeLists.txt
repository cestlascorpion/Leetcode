cmake_minimum_required(VERSION 3.10)

project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Leetcode main.cpp config.h
        Leetcode293cn/Leetcode293cn.cpp Leetcode293cn/Leetcode293cn.h Leetcode299cn/Leetcode299cn.cpp Leetcode299cn/Leetcode299cn.h Leetcode303cn/NumArray.cpp Leetcode303cn/NumArray.h)

