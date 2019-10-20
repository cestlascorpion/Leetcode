//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE695_H
#define LEETCODE_LEETCODE695_H

#include <config.h>

class Leetcode695 {

public:
    int maxAreaOfIsland(vector<vector<int>> &grid);

    int calArea(int m, int n, int i, int j, vector<vector<int>> &grid);
};


#endif //LEETCODE_LEETCODE695_H
