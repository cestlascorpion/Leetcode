//
// Created by Wang on 2019/12/18.
//

#include "Leetcode888cn.h"

vector<int> Leetcode888cn::fairCandySwap(vector<int> &A, vector<int> &B) {
    int sum_a = accumulate(A.begin(), A.end(), 0); // 1    6/2 = 3
    int sum_b = accumulate(B.begin(), B.end(), 0); // 2 3  6/2 = 3
    int avg = (sum_a + sum_b) / 2;
    set<int> s(B.begin(), B.end());
    for (const auto &a : A) {
        int b = a - (sum_a - sum_b) / 2;
        if (s.count(b) != 0) {
            return {a, b};
        }
    }
    return {};
}
