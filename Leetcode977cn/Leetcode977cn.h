//
// Created by Wang on 2019/12/21.
//

#ifndef LEETCODE_LEETCODE977CN_H
#define LEETCODE_LEETCODE977CN_H

#include "config.h"

class Leetcode977cn {
public:
    vector<int> sortedSquares(vector<int> &A) {
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
};

#endif // LEETCODE_LEETCODE977CN_H
