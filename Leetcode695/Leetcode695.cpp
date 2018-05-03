//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode695.h"

int Leetcode695::maxAreaOfIsland(vector<vector<int>> &grid) {
    int ans = 0;
    if (grid.empty() || grid[0].empty())
        return ans;

    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1)
                ans = max(ans, calArea(m, n, i, j, grid));
        }
    }
    return ans;
}

int Leetcode695::calArea(int m, int n, int i, int j, vector<vector<int>> &grid) {
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || grid[i][j] != 1)
        return 0;

    if (grid[i][j] == 1) {
        grid[i][j] = 0;
        return 1 +
               calArea(m, n, i - 1, j, grid) +
               calArea(m, n, i + 1, j, grid) +
               calArea(m, n, i, j - 1, grid) +
               calArea(m, n, i, j + 1, grid);
    }
    return 0;
}
