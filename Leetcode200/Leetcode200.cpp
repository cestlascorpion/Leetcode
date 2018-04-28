//
// Created by cestl on 2018/4/28 0028.
//

#include "Leetcode200.h"

int Leetcode200::numIslands(vector<vector<char>> &grid) {
    if (grid.empty() || grid[0].empty())
        return 0;

    int row = grid.size();
    int col = grid[0].size();

    int ans = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (grid[i][j] == '1') {
                ++ans;
                //cout << " i:j = " << i << ":" << j << endl;
                helper(grid, i, j);
            }
        }
    }
    return ans;
}

void Leetcode200::helper(vector<vector<char>> &grid, int i, int j) {
    //cout << " ----->> " << i << ":" << j << endl;
    int r = grid.size() - 1;
    int c = grid[0].size() - 1;
    grid[i][j] = '0';

    if (i + 1 <= r && grid[i + 1][j] == '1')
        helper(grid, i + 1, j);
    if (i - 1 >= 0 && grid[i - 1][j] == '1')
        helper(grid, i - 1, j);
    if (j + 1 <= c && grid[i][j + 1] == '1')
        helper(grid, i, j + 1);
    if (j - 1 >= 0 && grid[i][j - 1] == '1')
        helper(grid, i, j - 1);
}

void Leetcode200::test200() {
    vector<char> v0 = {'1', '1', '0', '0', '0'};
    vector<char> v1 = {'1', '1', '0', '0', '0'};
    vector<char> v2 = {'0', '0', '1', '0', '0'};
    vector<char> v3 = {'0', '0', '0', '1', '1'};
    vector<vector<char>> grid = {v0, v1, v2, v3};
    cout << "The number of islands is " << numIslands(grid) << endl;
}
