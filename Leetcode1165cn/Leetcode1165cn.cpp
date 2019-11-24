//
// Created by Wang on 2019/11/22.
//

#include "Leetcode1165cn.h"

int Leetcode1165cn::calculateTime(string keyboard, string word) {
    if(word.empty())
        return 0;
    vector<int> dict(26);
    for (int i = 0; i < keyboard.size(); ++i) {
        dict[keyboard[i] - 'a'] = i;
    }
    int res = 0;
    for (int i = 1; i < word.size(); ++i) {
        res += abs(dict[word[i] - 'a'] - dict[word[i - 1] - 'a']);
    }
    return res + dict[word[0] - 'a'];
}
