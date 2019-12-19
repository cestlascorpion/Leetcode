cmake_minimum_required(VERSION 3.10)

project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Leetcode main.cpp config.h
        Leetcode976cn/Leetcode976cn.cpp Leetcode976cn/Leetcode976cn.h)


