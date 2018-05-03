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

void Leetcode5::test5() {
    vector<int> nums = {1, 0, 3, 12};
    moveZeroes(nums);
    for (auto item : nums)
        cout << item << " ";
    cout << endl;
}
