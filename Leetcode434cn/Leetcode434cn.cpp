//
// Created by Wang on 2019/11/27.
//

#include "Leetcode434cn.h"

int Leetcode434cn::countSegments(string s) {
    int res = 0;
    int l = 0;
    while (true) {
        while (l < s.size() && s[l] == ' ') {
            ++l;
        }
        if (l == s.size()) {
            break;
        }
        ++res;
        int r = l;
        while (r < s.size() && s[r] != ' ') {
            ++r;
        }
        if (r == s.size()) {
            break;
        }
        l = r;
    }
    return res;
}
