cmake_minimum_required(VERSION 3.10)

project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Leetcode main.cpp config.h
        Leetcode266cn/Leetcode266cn.h
        Leetcode266cn/Leetcode266cn.cpp Leetcode256cn/Leetcode256cn.cpp Leetcode256cn/Leetcode256cn.h Leetcode270cn/Leetcode270cn.cpp Leetcode270cn/Leetcode270cn.h Leetcode276cn/Leetcode276cn.cpp Leetcode276cn/Leetcode276cn.h)
