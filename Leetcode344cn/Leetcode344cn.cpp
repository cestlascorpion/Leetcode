//
// Created by Wang on 2019/10/13.
//

#include "Leetcode344cn.h"

void Leetcode344cn::reverseString(vector<char> &s) {
    int lo = 0;
    int hi = s.size() - 1;
    while (lo < hi) {
        swap(s[lo], s[hi]);
        ++lo;
        --hi;
    }
}
