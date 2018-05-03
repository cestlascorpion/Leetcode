//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode75.h"

void Leetcode75::sortColors(vector<int> &nums) {
    if (nums.empty())
        return;
    int red = 0;
    int blue = nums.size() - 1;
    int cur = 0;
    while (cur <= blue) {
        if (nums[cur] == 0) {
            swap(nums[red++], nums[cur++]);
        } else if (nums[cur] == 1) {
            cur++;
        } else {
            swap(nums[blue--], nums[cur]);
        }
    }
}

void Leetcode75::test75() {
    vector<int> nums;
    nums = {0, 0, 0, 1, 1, 1, 2, 2, 2};
    sortColors(nums);
    for (auto item:nums) {
        cout << item << " ";
    }
    cout << endl;
    nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (auto item:nums) {
        cout << item << " ";
    }
    cout << endl;
    nums = {2, 2, 2, 0, 0, 0, 1, 1, 1};
    sortColors(nums);
    for (auto item:nums) {
        cout << item << " ";
    }
}
