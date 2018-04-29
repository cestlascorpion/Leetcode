//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode217.h"

bool Leetcode217::containsDuplicate2(vector<int> &nums) {
    if (nums.empty())
        return false;
    unordered_set<int> set(nums.begin(), nums.end());
    return nums.size() != set.size();
}

bool Leetcode217::containsDuplicate(vector<int> &nums) {
    if (nums.empty())
        return false;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] == nums[i + 1])
            return true;
    }
    return false;
}
