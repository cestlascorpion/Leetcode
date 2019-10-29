//
// Created by Wang on 2019/10/30.
//

#include "Leetcode59cn.h"

vector<vector<int>> Leetcode59cn::generateMatrix(int n) {
    vector<vector<int>> res;
    res.reserve(n);
    for (int i = 0; i < n; ++i) {
        res.emplace_back(n, 0);
    }
    int u = 0;
    int d = n - 1;
    int l = 0;
    int r = n - 1;
    int num = 1;

    while (true) {
        for (int i = l; i <= r; ++i) {
            res[u][i] = num;
            ++num;
        }
        if (++u > d) {
            break;
        }

        for (int i = u; i <= d; ++i) {
            res[i][r] = num;
            ++num;
        }
        if (--r < l) {
            break;
        }

        for (int i = r; i >= l; --i) {
            res[d][i] = num;
            ++num;
        }
        if (--d < u) {
            break;
        }

        for (int i = d; i >= u; --i) {
            res[i][l] = num;
            ++num;
        }
        if (++l > r) {
            break;
        }
    }
    return res;
}
