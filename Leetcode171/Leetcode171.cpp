//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode171.h"

int Leetcode171::titleToNumber(string s) {
    int ans = 0;
    if (s.empty())
        return ans;
    int base = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        ans = (s[i] - 'A' + 1) * base + ans;
        base = base * 26;
    }
    return ans;
}
