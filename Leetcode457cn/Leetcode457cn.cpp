//
// Created by Wang on 2019/11/28.
//

#include "Leetcode457cn.h"

bool Leetcode457cn::repeatedSubstringPattern(string s) {
    int len = s.size();
    for (int i = 2; i <= len; ++i) {
        if (len % i == 0 && valid(s, len/i)) {
            return true;
        }
    }
    return false;
}

bool Leetcode457cn::valid(const string &s, int len) {
    for (int i = len; i < s.size(); ++i) {
        if (s[i] != s[i % len]) {
            return false;
        }
    }
    return true;
}
