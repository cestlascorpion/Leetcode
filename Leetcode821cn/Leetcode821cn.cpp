//
// Created by Wang on 2019/12/3.
//

#include "Leetcode821cn.h"

vector<int> Leetcode821cn::shortestToChar(string S, char C) {
    vector<int> pos;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == C) {
            pos.push_back(i);
        }
    }
    vector<int> res;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == C) {
            res.push_back(0);
        } else {
            auto min = helper(i, pos);
            res.push_back(min);
        }
    }
    return res;
}

int Leetcode821cn::helper(int i, vector<int> pos) {
    auto iter = upper_bound(pos.begin(), pos.end(), i);
    if (iter == pos.begin())
        return pos[0] - i;
    if (iter == pos.end())
        return i - pos[pos.size() - 1];

    int right = *iter - i;
    --iter;
    int left = i - *iter;
    return min(left, right);
}
