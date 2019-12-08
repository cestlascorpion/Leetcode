//
// Created by Wang on 2019/12/8.
//

#include "Leetcode908cn.h"

int Leetcode908cn::smallestRangeI(vector<int> &A, int K) {
    int min = A[0];
    int max = A[0];
    for (const auto &num : A) {
        min = std::min(min, num);
        max = std::max(min, num);
    }
    return min + K >= max - K ? 0 : max - min - 2 * K;
}
