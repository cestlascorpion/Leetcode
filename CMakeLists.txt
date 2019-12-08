cmake_minimum_required(VERSION 3.10)

project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Leetcode main.cpp config.h Leetcode994cn/Leetcode994cn.cpp Leetcode994cn/Leetcode994cn.h Leetcode908cn/Leetcode908cn.cpp Leetcode908cn/Leetcode908cn.h Leetcode1114cn/Leetcode1114cn.cpp Leetcode1114cn/Leetcode1114cn.h)

