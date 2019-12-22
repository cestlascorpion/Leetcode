//
// Created by Wang on 2019/12/22.
//

#include "Leetcode905cn.h"

vector<int> Leetcode905cn::sortArrayByParity(vector<int> &A) {
    int l = 0, r = A.size() - 1;
    while (l < r) {
        while (l < r && A[l] % 2 == 0) {
            ++l;
        }
        while (l < r && A[r] % 2 != 0) {
            --r;
        }
        swap(A[l], A[r]);
    }
    return A;
}
