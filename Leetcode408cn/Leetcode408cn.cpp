//
// Created by Wang on 2019/11/27.
//

#include "Leetcode408cn.h"

bool Leetcode408cn::validWordAbbreviation(string word, string abbr) {
    int m = 0;
    int n = 0;
    while (true) {
        if (m >= word.size() || n >= abbr.size()) {
            break;
        }
        if (abbr[n] >= 'a' && abbr[n] <= 'z') {
            if (word[m] == abbr[n]) {
                ++m;
                ++n;
            } else {
                return false;
            }
        } else {
            int l = n;
            while (n < abbr.size() && abbr[n] >= '0' && abbr[n] <= '9') {
                ++n;
            }
            int num = stoi(abbr.substr(l, n - l).c_str(), nullptr, 10);
            if (num == 0) {
                return false;
            }
            while (num > 0) {
                ++m;
                --num;
            }
        }
    }
    return m == word.size() && n == abbr.size();
}
