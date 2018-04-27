//
// Created by hans on 4/27/18.
//

#include "Leetcode198.h"

int Leetcode198::rob(vector<int> &nums) {
    if (nums.empty())
        return 0;
    int pre = 0, cur = 0;
    for (auto item:nums) {
        int temp = max(pre + item, cur);
        pre = cur;
        cur = temp;
    }
    return cur;
}

void Leetcode198::test198() {
    vector<int> nums = {3, 2, 1, 5};
    cout << " max -> 8, output is " << rob(nums) << endl;
}
