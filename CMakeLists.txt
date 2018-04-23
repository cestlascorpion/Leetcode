cmake_minimum_required(VERSION 3.10)
project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

add_executable(Leetcode main.cpp
        config.h
        BinaryTree/BinaryTree.cpp
        BinaryTree/BinaryTree.h
        Sort/Sort.cpp
        Sort/Sort.h)