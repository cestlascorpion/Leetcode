//
// Created by Wang on 2019/11/20.
//

#include "Leetcode1151cn.h"

int Leetcode1151cn::heightChecker(vector<int> &heights) {
    map<int, int> dict;
    for (const auto &h:heights) {
        ++dict[h];
    }
    int res = 0;
    int idx = 0;
    for (const auto &p:dict) {
        for (int i = 0; i < p.second; ++i) {
            if (heights[idx] != p.first)
                ++res;
            ++idx;
        }
    }
    return res;
}
