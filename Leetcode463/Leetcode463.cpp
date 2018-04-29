//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode463.h"

int Leetcode463::islandPerimeter(vector<vector<int>> &grid) {
    int ans = 0;
    if (grid.empty() || grid[0].empty())
        return ans;

    int m = grid.size();
    int n = grid[0].size();
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (grid[row][col] == 1) {
                if (row == 0)
                    ++ans;
                if (row == m - 1)
                    ++ans;
                if (row > 0 && grid[row - 1][col] == 0)
                    ++ans;
                if (row < m - 1 && grid[row + 1][col] == 0)
                    ++ans;

                if (col == 0)
                    ++ans;
                if (col == n - 1)
                    ++ans;
                if (col > 0 && grid[row][col - 1] == 0)
                    ++ans;
                if (col < n - 1 && grid[row][col + 1] == 0)
                    ++ans;
            }
        }
    }
    return ans;
}
