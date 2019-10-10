//
// Created by Wang on 2019/10/10.
//

#include "Leetcode1207cn.h"

bool Leetcode1207cn::uniqueOccurrences(vector<int> &arr) {
    if (arr.empty()) {
        return true;
    }

    unordered_map<int, unsigned> occ;
    for (const auto &num:arr) {
        ++occ[num];
    }
    if (occ.size() == 1) {
        return true;
    }
    unordered_set<unsigned> uni;
    unsigned num = 0;
    for (const auto &pair:occ) {
        uni.insert(pair.second);
        ++num;
        if (uni.size() < num) {
            return false;
        }
    }
    return true;
}
