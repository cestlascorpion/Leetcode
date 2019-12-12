//
// Created by Wang on 2019/12/12.
//

#include "Leetcode844cn.h"

bool Leetcode844cn::backspaceCompare(string S, string T) {
    int len_s = helper(S);
    int len_t = helper(T);
    if (len_s != len_t)
        return false;
    for (int i = 0; i < len_s; ++i) {
        if (S[i] != T[i])
            return false;
    }
    return true;
}

int Leetcode844cn::helper(string &str) {
    int len = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != '#') {
            str[len] = str[i];
            ++len;
        } else {
            if (len == 0) {
                continue;
            }
            --len;
        }
    }
    return len;
}
