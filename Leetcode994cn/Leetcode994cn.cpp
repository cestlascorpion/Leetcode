//
// Created by Wang on 2019/12/8.
//

#include "Leetcode994cn.h"

int Leetcode994cn::orangesRotting(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
        return -1;
    }

    bool has_good = false;
    bool has_bad = false;
    bool changed = false;
    int counter = 0;

    int u = 0, d = grid.size() - 1;
    int l = 0, r = grid[0].size() - 1;
    while (true) {
        for (int row = u; row <= d; ++row) {
            for (int col = l; col <= r; ++col) {
                if (grid[row][col] == 2) {
                    has_bad = true;
                    mark_go_bad(row, col, grid);
                }
                if (grid[row][col] == 1) {
                    has_good = true;
                }
            }
        }
        if (!has_bad) {
            break;
        }
        update_grid(grid, changed);
        if (!changed) {
            break;
        }
        ++counter;
        changed = false;
    }

    if (!has_bad && has_good) {
        return -1;
    }

    for (int row = u; row <= d; ++row) {
        for (int col = l; col <= r; ++col) {
            if (grid[row][col] == 1) {
                return -1;
            }
        }
    }
    return counter;
}

void Leetcode994cn::mark_go_bad(int row, int col, vector<vector<int>> &grid) {
    int u = 0, d = grid.size() - 1;
    int l = 0, r = grid[0].size() - 1;
    if (row - 1 >= u && grid[row - 1][col] == 1) {
        grid[row - 1][col] = -2;
    }
    if (row + 1 <= d && grid[row + 1][col] == 1) {
        grid[row + 1][col] = -2;
    }
    if (col - 1 >= l && grid[row][col - 1] == 1) {
        grid[row][col - 1] = -2;
    }
    if (col + 1 <= r && grid[row][col + 1] == 1) {
        grid[row][col + 1] = -2;
    }
}

void Leetcode994cn::update_grid(vector<vector<int>> &grid, bool &changed) {
    int u = 0, d = grid.size() - 1;
    int l = 0, r = grid[0].size() - 1;
    for (int row = u; row <= d; ++row) {
        for (int col = l; col <= r; ++col) {
            if (grid[row][col] == -2) {
                changed = true;
                grid[row][col] = 2;
            }
        }
    }
}
