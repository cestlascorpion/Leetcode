//
// Created by Wang on 2019/11/27.
//

#include "Leetcode443cn.h"

//["a","a","b","b","c","c","c"]
//
int Leetcode443cn::compress(vector<char> &chars) {
    int idx = 0;
    int slow = 0;
    while (slow < chars.size()) {
        int fast = slow + 1; // 1
        while (fast < chars.size() && chars[fast] == chars[slow]) {
            ++fast;
        }
        --fast;
        chars[idx++] = chars[slow];// idx = 1
        if (fast - slow > 0) {
            string num = to_string(fast - slow + 1);
            for (const auto &n:num) {
                chars[idx++] = n;
            }
        }
        slow = fast + 1;
    }
    return idx;
}
