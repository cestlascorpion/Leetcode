//
// Created by Wang on 2019/10/13.
//

#include "Leetcode219cn.h"

bool Leetcode219cn::containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> m;// num, first idx
    for (int i = 0; i < nums.size(); ++i) {
        auto iter = m.find(nums[i]);
        if (iter == m.end()) {
            m[nums[i]] = i;
        } else {
            if (k >= i - iter->second) {
                return true;
            }
            m[nums[i]] = i;
        }
    }
    return false;
}
