//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode796.h"

bool Leetcode796::rotateString(string A, string B) {
    if (A.empty() && B.empty())
        return true;
    if (A.empty() || B.empty() || A.length() != B.length())
        return false;
    int len = A.length();
    for (int i = 0; i < len; ++i) {
        if (A[i] == B[0]) {
            if (isSame(A, B, i, len))
                return true;
        }
    }
    return false;
}

bool Leetcode796::isSame(string &A, string &B, int index, int length) {
    for (int i = 0; i < length; ++i) {
        if (A[(index + i) % length] != B[i])
            return false;
    }
    return true;
}
