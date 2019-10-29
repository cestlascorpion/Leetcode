//
// Created by Wang on 2019/10/30.
//

#include "Leetcode266cn.h"

bool Leetcode266cn::canPermutePalindrome(string s) {
    unordered_map<char, int> dict;
    for (const char &ch : s) {
        ++dict[ch];
    }
    bool single = false;
    for (const auto &p : dict) {
        if (p.second % 2 == 0) {
            continue;
        } else {
            if (!single) {
                single = true;
            } else {
                return false;
            }
        }
    }
    return true;
}
