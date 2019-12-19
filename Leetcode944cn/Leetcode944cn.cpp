//
// Created by Wang on 2019/12/19.
//

#include "Leetcode944cn.h"

int Leetcode944cn::minDeletionSize(vector<string> &A) {
    int res = 0;
    if (A.empty())
        return res;

    int rows = A.size();
    int cols = A[0].size();
    for (int i = 0; i < cols; ++i) {
        for (int j = 1; j < rows; ++j) {
            if (A[j][i] < A[j - 1][i]) {
                ++res;
                break;
            }
        }
    }
    return res;
}
