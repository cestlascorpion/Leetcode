//
// Created by Wang on 2019/11/7.
//

#include "Leetcode1221.h"

int Leetcode1221::balancedStringSplit(string s) {
    int l = 0;
    int r = 0;
    int res = 0;
    for (int i = 0; i != s.size(); ++i) {
        if (s[i] == 'L') {
            ++l;
        } else {
            ++r;
        }
        if (l == r) {
            l = 0;
            r = 0;
            ++res;
        }
    }
    return res;
}
