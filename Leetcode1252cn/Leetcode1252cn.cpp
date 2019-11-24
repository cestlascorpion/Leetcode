//
// Created by Wang on 2019/11/22.
//

#include "Leetcode1252cn.h"

int Leetcode1252cn::oddCells(int n, int m, vector<vector<int>> &indices) {
    vector<int> rows(n, 0);
    vector<int> cols(m, 0);
    for (const auto &v:indices) {
        int row = v[0];
        ++rows[row];
        int col = v[1];
        ++cols[col];
    }
    int odd_r = 0;
    for (const auto &row:rows) {
        if ((row & 1) == 1) {
            ++odd_r;
        }
    }
    int odd_c = 0;
    for (const auto &col:cols) {
        if ((col & 1) == 1) {
            ++odd_c;
        }
    }
    return odd_r * (m - odd_c) + odd_c * (n - odd_r);
}
