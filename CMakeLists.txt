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
        config.h
        main.cpp
        Sort/Sort.cpp
        Sort/Sort.h
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
        Leetcode136/Leetcode136.cpp
        Leetcode136/Leetcode136.h
        Leetcode350/Leetcode350.cpp
        Leetcode350/Leetcode350.h
        Leetcode66/Leetcode66.cpp
        Leetcode66/Leetcode66.h
        Leetcode283/Leetcode283.cpp
        Leetcode1/Leetcode1.cpp
        Leetcode1/Leetcode1.h
        Leetcode36/Leecode36.cpp
        Leetcode36/Leecode36.h
        Leetcode48/Leetcode48.cpp
        Leetcode48/Leetcode48.h
        Leetcode344/Leetcode344.cpp
        Leetcode344/Leetcode344.h
        Leetcode7/Leetcode7.cpp
        Leetcode7/Leetcode7.h
        Leetcode387/Leetcode387.cpp
        Leetcode387/Leetcode387.h Leetcode242/Leetcode242.cpp Leetcode242/Leetcode242.h Leetcode125/Leetcode125.cpp Leetcode125/Leetcode125.h Leetcode8/Leetcode8.cpp Leetcode8/Leetcode8.h Leetcode28/Leetcode28.cpp Leetcode28/Leetcode28.h Leetcode38/Leetcode38.cpp Leetcode38/Leetcode38.h Leetcode14/Leetcode14.cpp Leetcode14/Leetcode14.h Leetcode237/Leetcode237.cpp Leetcode237/Leetcode237.h Leetcode174/Leetcode174.cpp Leetcode174/Leetcode174.h Leetcode77/Leetcode77.cpp Leetcode77/Leetcode77.h Leetcode21/Leetcode21.cpp Leetcode21/Leetcode21.h Leetcode234/Leetcode234.cpp Leetcode234/Leetcode234.h Leetcode141/Leetcode141.cpp Leetcode141/Leetcode141.h)
