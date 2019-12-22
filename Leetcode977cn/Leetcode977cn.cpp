//
// Created by Wang on 2019/12/21.
//

#include "Leetcode977cn.h"

vector<int> Leetcode977cn::sortedSquares(vector<int> &A) {
    vector<int> res(A.size());
    int l = 0, r = A.size() - 1;
    int r_idx = A.size() - 1;
    while (l <= r) {
        if (abs(A[r]) > abs(A[l])) {
            res[r_idx] = A[r] * A[r];
            --r;
        } else {
            res[r_idx] = A[l] * A[l];
            ++l;
        }
        --r_idx;
    }
    return res;
}
