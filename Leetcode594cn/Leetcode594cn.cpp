//
// Created by Wang on 2019/12/2.
//

#include "Leetcode594cn.h"

int Leetcode594cn::findLHS(vector<int> &nums) {
    if (nums.empty())
        return 0;
    map<int, int> m;
    for (const auto &num : nums) {
        ++m[num];
    }
    int res = 0;
    auto pre = m.begin();
    auto cur = ++m.begin();
    while (cur != m.end()) {
        if (pre->first + 1 == cur->first) {
            res = max(res, pre->second + cur->second);
        }
        pre = cur;
        ++cur;
    }
    return res;
}
