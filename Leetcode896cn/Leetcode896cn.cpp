//
// Created by Wang on 2019/12/18.
//

#include "Leetcode896cn.h"

bool Leetcode896cn::isMonotonic(vector<int> &A) { return increasing(A) || decreasing(A); }

bool Leetcode896cn::increasing(vector<int> &A) {
    for (int i = 0; i < A.size() - 1; ++i)
        if (A[i] > A[i + 1])
            return false;
    return true;
}
bool Leetcode896cn::decreasing(vector<int> &A) {
    for (int i = 0; i < A.size() - 1; ++i)
        if (A[i] < A[i + 1])
            return false;
    return true;
}
