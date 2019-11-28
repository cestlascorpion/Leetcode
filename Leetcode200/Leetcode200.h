//
// Created by cestl on 2018/4/28 0028.
//

#ifndef LEETCODE_LEETCODE200_H
#define LEETCODE_LEETCODE200_H

#include "config.h"

class Leetcode200 {
public:
    int numIslands(vector<vector<char>> &grid);

    void test200();

private:
    void helper(vector<vector<char>> &grid, int i, int j);
};


#endif //LEETCODE_LEETCODE200_H
