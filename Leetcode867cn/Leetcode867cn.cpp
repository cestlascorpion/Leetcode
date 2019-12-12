//
// Created by Wang on 2019/12/12.
//

#include "Leetcode867cn.h"

vector<vector<int>> Leetcode867cn::transpose(vector<vector<int>> &A) {
    int R, C;
    if (!(R = A.size()) || !(C = A[0].size()))
        return vector<vector<int>>();
    vector<vector<int>> ans(C, vector<int>(R));
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < R; ++j) {
            ans[i][j] = A[j][i];
        }
    }
    return ans;
}
