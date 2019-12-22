//
// Created by Wang on 2019/12/22.
//

#include "Leetcode922cn.h"

vector<int> Leetcode922cn::sortArrayByParityII(vector<int> &A) {
    int idx = 0;
    int odd = 0;
    int even = 0;
    while (idx < A.size()) {
        while (odd < A.size() && A[odd] % 2 == 0)
            ++odd;
        while (even < A.size() && A[even] % 2 != 0)
            ++even;
        if (idx % 2 != 0) {
            swap(A[idx], A[odd]);
            ++odd;
        } else {
            swap(A[idx], A[even]);
            ++even;
        }
        ++idx;
    }
    return A;
}

vector<int> Leetcode922cn::sortArrayByParityII2(vector<int> &A) {
    vector<int> res(A.size());
    int odd = 0;
    int even = 0;
    for (int i = 0; i < A.size(); i += 2) {
        while (odd < A.size() && A[odd] % 2 == 0)
            ++odd;
        while (even < A.size() && A[even] % 2 != 0)
            ++even;
        res[i] = A[even++];
        res[i + 1] = A[odd++];
    }
    return res;
}
