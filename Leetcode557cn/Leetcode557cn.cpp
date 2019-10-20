//
// Created by Wang on 2019/10/20.
//

#include "Leetcode557cn.h"

string Leetcode557cn::reverseWords(string s) {
    int idx = 0;
    while (idx < s.size()) {
        int p = idx + 1;
        while (p < s.size() && s[p] != ' ') {
            ++p;
        }
        helper(s, idx, p - 1);
        idx = p + 1;
    }
    return s;
}

void Leetcode557cn::helper(string &s, int l, int r) {
    while (l < r) {
        swap(s[l], s[r]);
        ++l;
        --r;
    }
}
