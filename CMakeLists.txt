cmake_minimum_required(VERSION 3.10)

project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Leetcode main.cpp config.h
        Leetcode1046cn/Leetcode1046cn.cpp Leetcode1046cn/Leetcode1046cn.h Leetcode163cn/Leetcode163cn.cpp Leetcode163cn/Leetcode163cn.h Leetcode208cn/Trie.cpp Leetcode208cn/Trie.h Leetcode285cn/Leetcode285cn.cpp Leetcode285cn/Leetcode285cn.h Leetcode289cn/Leetcode289cn.cpp Leetcode289cn/Leetcode289cn.h)

