//
// Created by Wang on 2019/11/11.
//

#include "Leetcode299cn.h"

string Leetcode299cn::getHint(string secret, string guess) {
    int bulls = 0;
    int cows = 0;
    map<char, int> dict;
    vector<char> rest;
    for (int i = 0; i < secret.size(); ++i) {
        if (guess[i] == secret[i]) {
            ++bulls;
        } else {
            ++dict[secret[i]];
            rest.push_back(guess[i]);
        }
    }
    for (const auto &ch : rest) {
        auto iter = dict.find(ch);
        if (iter != dict.end()) {
            if (iter->second > 0) {
                --iter->second;
                ++cows;
            }
        }
    }
    string ans = to_string(bulls) + "A" + to_string(cows) + "B";
    return ans;
}
