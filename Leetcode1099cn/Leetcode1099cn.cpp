//
// Created by Wang on 2019/12/3.
//

#include "Leetcode1099cn.h"

int Leetcode1099cn::twoSumLessThanK(vector<int> &A, int K) {
    sort(A.begin(), A.end());
    int l = 0;
    int r = A.size() - 1;
    int res = K;
    while (l < r) {
        int sum = A[l] + A[r];
        if (sum == K) {
            return K;
        } else if (sum > K) {
            --r;
        } else {
            if (res == K)
                res = sum;
            else {
                res = sum > res ? sum : res;
            }
            ++l;
        }
    }
    return res;
}
