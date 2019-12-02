//
// Created by Wang on 2019/12/3.
//

#include "Leetcode748cn.h"

string Leetcode748cn::shortestCompletingWord(string licensePlate, vector<string> &words) {
    vector<int> dict(26, 0);
    for (const auto &ch : licensePlate) {
        if (ch >= 'a' && ch <= 'z') {
            ++dict[ch - 'a'];
            continue;
        }
        if (ch >= 'A' && ch <= 'Z') {
            ++dict[ch - 'A'];
            continue;
        }
    }

    string res;
    for (const auto &word : words) {
        if (!valid(word, dict)) {
            continue;
        }
        if (res.empty() || res.size() > word.size()) {
            res = word;
        }
    }
    return res;
}

bool Leetcode748cn::valid(const string &word, vector<int> dict) {
    for (const auto &ch : word) {
        if (ch >= 'a' && ch <= 'z') {
            --dict[ch - 'a'];
            continue;
        }
        if (ch >= 'A' && ch <= 'Z') {
            --dict[ch - 'A'];
            continue;
        }
    }
    for (const auto &num : dict) {
        if (num > 0) {
            return false;
        }
    }
    return true;
}
