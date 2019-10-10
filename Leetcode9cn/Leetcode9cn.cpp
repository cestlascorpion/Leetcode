//
// Created by Wang on 2019/10/13.
//

#include "Leetcode9cn.h"

bool Leetcode9cn::isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    string s = to_string(x);
    int low = 0;
    int high = s.size() - 1;
    while (low < high) {
        if (s[low] != s[high]) {
            return false;
        }
        ++low;
        --high;
    }
    return true;
}
