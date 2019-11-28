//
// Created by Wang on 2019/11/27.
//

#include "Leetcode414cn.h"

int Leetcode414cn::thirdMax(vector<int> &nums) {
    map<int, int> dict;
    for (const auto &num:nums) {
        ++dict[num];
    }
    if (dict.size() <= 3) {
        return dict.rbegin()->first;
    }
    return (++(++dict.rbegin()))->first;
}
