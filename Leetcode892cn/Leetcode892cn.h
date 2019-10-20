//
// Created by Wang on 2019/10/20.
//

#ifndef LEETCODE_LEETCODE892CN_H
#define LEETCODE_LEETCODE892CN_H

#include <config.h>

class Leetcode892cn {
public:
    int surfaceArea(vector<vector<int>> &grid);

    int helper(const vector<vector<int>> &grid, int i, int j, int n);
};

#endif // LEETCODE_LEETCODE892CN_H
