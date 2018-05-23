//
// Created by hans on 18-4-24.
//

#include "Leetcode5.h"

void Leetcode5::moveZeroes(vector<int> &nums) {
    if (nums.empty())
        return;
    for (int i = 0, j = 0; i < nums.size(); ++i) {
        if (nums[i]) {
            swap(nums[i], nums[j++]);
        }
    }
}

