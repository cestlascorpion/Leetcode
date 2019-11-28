//
// Created by Wang on 2019/11/28.
//

#include "Leetcode455cn.h"

int Leetcode455cn::findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0;
    int j = 0;
    int res = 0;
    while (i < g.size() && j < s.size()) {
        while (j < s.size() && s[j] < g[i]) {
            ++j;
        }
        if (j == s.size()) {
            break;
        }
        ++res;
        ++j;
        ++i;
    }
    return res;
}
