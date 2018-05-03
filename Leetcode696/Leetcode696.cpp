//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode696.h"

int Leetcode696::countBinarySubstrings(string s) {
    int index = 0;
    vector<int> mount;
    while (index < s.length()) {
        char ch = s[index];
        int length = 0;
        while (index < s.length() && ch == s[index]) {
            ++index;
            ++length;
        }
        mount.push_back(length);
    }
    if (mount.empty())
        return 0;
    int ans = 0;
    for (int i = 0; i + 1 < mount.size(); i++)
        ans += min(mount[i], mount[i + 1]);
    return ans;
}

int Leetcode696::countBinarySubstrings2(string s) {
    int pre = 0;
    int cur = 0;
    int index = 0;
    int ans = 0;
    while (index < s.length()) {
        char ch = s[index];
        while (ch == s[index]) {
            cur++;
            index++;
        }
        ans += min(pre, cur);
        pre = cur;
        cur = 0;
    }
    return ans;
}
