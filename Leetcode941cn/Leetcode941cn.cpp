//
// Created by Wang on 2019/12/19.
//

#include "Leetcode941cn.h"

bool Leetcode941cn::validMountainArray(vector<int> &A) {
    if (A.size() < 3)
        return false;

    int l = 0, r = A.size() - 1;
    bool f1 = false, f2 = false;
    while (l < A.size() - 1 && A[l + 1] > A[l]) {
        f1 = true;
        ++l;
    }
    while (r > 0 && A[r] < A[r - 1]) {
        f2 = true;
        --r;
    }
    return l == r && f1 && f2;
}
