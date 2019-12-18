//
// Created by Wang on 2019/12/18.
//

#include "Leetcode883cn.h"

int Leetcode883cn::projectionArea(vector<vector<int>> &grid) {
    if (grid.empty())
        return 0;

    int xy = 0;
    int xz = 0;
    int yz = 0;

    int len = 0; // 最大行长度
    for (auto &row : grid) {
        if (row.empty())
            continue;
        len = std::max(len, int(row.size()));
        int max = row[0];
        for (int col : row) {
            max = std::max(max, col);
            if (col != 0) {
                ++xy;
            }
        }
        xz += max;
    }

    for (int col = 0; col < len; ++col) {
        int max = 0;
        for (auto &row : grid) {
            if (col < row.size()) {
                max = std::max(max, row[col]);
            }
        }
        yz += max;
    }
    // cout << xy << " " << xz << " " << yz << endl;
    return xy + xz + yz;
}
