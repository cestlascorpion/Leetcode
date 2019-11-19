//
// Created by Wang on 2019/11/20.
//

#include "Leetcode1071cn.h"

string Leetcode1071cn::gcdOfStrings(string str1, string str2) {
    if (str1.empty() || str2.empty()) {
        return string();
    }
    if (str1.size() < str2.size()) {
        swap(str1, str2);
    }
    int len = str2.size();
    bool valid = false;
    for (int i = 1; i < len; ++i) {
        if (is_valid(str1, str2, len, i)) {
            len = len / i;
            valid = true;
            break;
        }
    }
    if (valid)
        return str2.substr(0, len);
    return string();
}

bool Leetcode1071cn::is_valid(const string &str1, const string &str2, int len, int div) {
    if (len % div != 0) {
        return false;
    }
    len = len / div;
    if (str1.size() % len != 0) {
        return false;
    }
    for (int i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i % len]) {
            return false;
        }
    }
    return true;
}
