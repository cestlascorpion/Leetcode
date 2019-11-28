//
// Created by Wang on 2019/10/20.
//

#ifndef LEETCODE_LEETCODE796CN_H
#define LEETCODE_LEETCODE796CN_H

#include "config.h"

class Leetcode796cn {
public:
    bool rotateString(string A, string B);
    bool helper(const string &A, const string &B, int j);
};

#endif // LEETCODE_LEETCODE796CN_H
