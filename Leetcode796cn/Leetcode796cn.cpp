//
// Created by Wang on 2019/10/20.
//

#include "Leetcode796cn.h"

bool Leetcode796cn::rotateString(string A, string B) {
    if (A.size() != B.size()) {
        return false;
    }
    if (A.empty())
        return true;

    char head = A[0];
    for (int i = 0; i < B.size(); ++i) {
        if (B[i] == head) {
            if (helper(A, B, i)) {
                return true;
            }
        }
    }
    return false;
}

bool Leetcode796cn::helper(const string &A, const string &B, int j) {
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] != B[(i + j) % B.size()]) {
            return false;
        }
    }
    return true;
}
