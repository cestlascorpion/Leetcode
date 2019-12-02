//
// Created by Wang on 2019/11/29.
//

#include "Leetcode532cn.h"

int Leetcode532cn::findPairs(vector<int> &nums, int k) {
    int res = 0;
    map<int, int> m;
    for (const auto &num : nums) {
        ++m[num];
    }
    for (auto &p : m) {
        if (k == 0) {
            if (p.second > 1)
                res += p.second * (p.second - 1) / 2;
        } else {
            auto iter = m.find(p.first + k);
            if (iter != m.end())
                res += p.second * iter->second;
        }
    }
    return res;
}
