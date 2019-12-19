//
// Created by Wang on 2019/12/19.
//

#include "Leetcode976cn.h"

int Leetcode976cn::largestPerimeter(vector<int> &A) {
    sort(A.begin(), A.end());
    for (int i = A.size() - 3; i >= 0; --i) {
        if (A[i] + A[i + 1] > A[i + 2]) {
            return A[i] + A[i + 1] + A[i + 2];
        }
    }
    return 0;
}
