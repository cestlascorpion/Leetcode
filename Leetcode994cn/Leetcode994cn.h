//
// Created by Wang on 2019/12/8.
//

#ifndef LEETCODE_LEETCODE994CN_H
#define LEETCODE_LEETCODE994CN_H

#include "config.h"

class Leetcode994cn {
public:
    int orangesRotting(vector<vector<int>> &grid);
    void mark_go_bad(int row, int col, vector<vector<int>> &grid);
    void update_grid(vector<vector<int>> &grid, bool& changed);
};

#endif // LEETCODE_LEETCODE994CN_H
