//
// Created by Wang on 2019/10/20.
//

#include "Leetcode892cn.h"

int Leetcode892cn::surfaceArea(vector<vector<int>> &grid) {
    int area = 0;
    int n = grid.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            area += helper(grid, i, j, n);
        }
    }
    return area;
}

int Leetcode892cn::helper(const vector<vector<int>> &grid, int i, int j, int n) {
    if (grid[i][j] == 0) {
        return 0;
    }
    int res = 2;
    if (i > 0) {
        if (grid[i - 1][j] < grid[i][j]) {
            res += grid[i][j] - grid[i - 1][j];
        }
    } else {
        res += grid[i][j];
    }
    if (i < n - 1) {
        if (grid[i + 1][j] < grid[i][j]) {
            res += grid[i][j] - grid[i + 1][j];
        }
    } else {
        res += grid[i][j];
    }
    if (j > 0) {
        if (grid[i][j - 1] < grid[i][j]) {
            res += grid[i][j] - grid[i][j - 1];
        }
    } else {
        res += grid[i][j];
    }
    if (j < n - 1) {
        if (grid[i][j + 1] < grid[i][j]) {
            res += grid[i][j] - grid[i][j + 1];
        }
    } else {
        res += grid[i][j];
    }
    return res;
}
