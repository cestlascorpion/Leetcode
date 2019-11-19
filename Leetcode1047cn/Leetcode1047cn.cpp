//
// Created by Wang on 2019/11/20.
//

#include "Leetcode1047cn.h"

string Leetcode1047cn::removeDuplicates(string S) {
    int top = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (top  == 0 || S[i] != S[top - 1]) {
            S[top] = S[i];
            ++top;
        } else {
            --top;
        }
    }
    S.resize(top);
    return S;
}
