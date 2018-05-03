//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode680.h"

bool Leetcode680::validPalindrome(string s) {
    int low = 0;
    int high = s.length() - 1;
    while (low < high) {
        if (s[low] == s[high]) {
            low++;
            high--;
        } else
            return isvalid(s, low + 1, high) || isvalid(s, low, high - 1);
    }
    return true;
}

bool Leetcode680::isvalid(string &s, int low, int high) {
    while (low < high) {
        if (s[low] != s[high])
            return false;
        ++low;
        --high;
    }
    return true;
}
