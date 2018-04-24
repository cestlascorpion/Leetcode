cmake_minimum_required(VERSION 3.10)
project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(BinaryTree)
include_directories(Leetcode150)
include_directories(Leetcode189)
include_directories(Leetcode219)
include_directories(Leetcode26)
include_directories(Sort)

add_executable(Leetcode
        BinaryTree/BinaryTree.cpp
        BinaryTree/BinaryTree.h
        Leetcode150/Leetcode150.cpp
        Leetcode150/Leetcode150.h
        Leetcode189/Leetcode189.cpp
        Leetcode189/Leetcode189.h
        Leetcode219/Leetcode219.cpp
        Leetcode219/Leetcode219.h
        Leetcode26/Leetcode26.cpp
        Leetcode26/Leetcode26.h
        Sort/Sort.cpp
        Sort/Sort.h
        config.h
        main.cpp Leetcode136/Leetcode136.cpp Leetcode136/Leetcode136.h Leetcode350/Leetcode350.cpp Leetcode350/Leetcode350.h Leetcode66/Leetcode66.cpp Leetcode66/Leetcode66.h Leetcode5/Leetcode5.cpp Leetcode5/Leetcode5.h Leetcode1/Leetcode1.cpp Leetcode1/Leetcode1.h Leetcode36/Leecode36.cpp Leetcode36/Leecode36.h Leetcode48/Leetcode48.cpp Leetcode48/Leetcode48.h)
