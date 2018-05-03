//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode647.h"

int Leetcode647::countSubstrings(string s) {
    int ans = 0;
    if (s.length() <= 0)
        return ans;
    for (int i = 0; i < s.length(); i++) {
        int p1 = i;
        int p2 = i;
        int p3 = i;
        int p4 = i + 1;
        while (p1 >= 0 && p2 <= s.length() - 1 && s[p1] == s[p2]) {
            ++ans;
            --p1;
            ++p2;
        }
        while (p3 >= 0 && p4 <= s.length() - 1 && s[p3] == s[p4]) {
            ++ans;
            --p3;
            ++p4;
        }
    }
    return ans;
}
