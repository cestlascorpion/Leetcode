//
// Created by Wang on 2019/10/20.
//

#include "Leetcode5cn.h"

string Leetcode5cn::longestPalindrome(string s) {
    if (s.size() < 2)
        return s;

    int l = 0;
    int r = 0;
    int len = 0;
    for (int i = 0; i < s.size(); ++i) {
        int x1 = helper(s, i, i);
        int x2 = helper(s, i, i + 1);
        len = max(max(x1, x2), len);
        if (len > r - l + 1) {
            l = i - (len - 1) / 2;
            r = i + len / 2;
        }
    }
    return s.substr(l, len);
}

int Leetcode5cn::helper(string s, int l, int r) {
    while (l >= 0 && r < s.length() && s[r] == s[l]) {
        --l;
        ++r;
    }
    return r - l - 1;
}
