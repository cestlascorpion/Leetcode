//
// Created by Wang on 2019/12/2.
//

#ifndef LEETCODE_LEETCODE697CN_H
#define LEETCODE_LEETCODE697CN_H

#include "config.h"

class Leetcode697cn {
public:
    int findShortestSubArray(vector<int> &nums);

private:
    struct info {
        int count; // num
        int first; // idx
        int last;  // idx
    };
};

#endif // LEETCODE_LEETCODE697CN_H
