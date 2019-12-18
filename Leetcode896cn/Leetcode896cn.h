//
// Created by Wang on 2019/12/18.
//

#ifndef LEETCODE_LEETCODE896CN_H
#define LEETCODE_LEETCODE896CN_H

#include "config.h"

class Leetcode896cn {
public:
    bool isMonotonic(vector<int> &A);

private:
    bool increasing(vector<int> &A);

    bool decreasing(vector<int> &A);
};

#endif // LEETCODE_LEETCODE896CN_H
