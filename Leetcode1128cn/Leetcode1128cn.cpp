//
// Created by Wang on 2019/10/14.
//

#include "Leetcode1128cn.h"

int Leetcode1128cn::numEquivDominoPairs(vector<vector<int>> &dominoes) {
    map<pair<int, int>, int> map;
    for (const auto &v:dominoes) {
        if (v[0] < v[1]) {
            ++map[{v[0], v[1]}];
        } else {
            ++map[{v[1], v[0]}];
        }
    }

    int res = 0;
    for (const auto &pair:map) {
        res += helper(pair.second);
    }
    return res;
}

int Leetcode1128cn::helper(int x) {
    if (x < 2)
        return 0;

    return (x - 1) * x / 2;
}
