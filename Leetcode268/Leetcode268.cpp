//
// Created by hans on 4/27/18.
//

#include "Leetcode268.h"

int Leetcode268::missingNumber(vector<int> &nums) {
    if (nums.empty())
        return -1;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return (nums.size() + 1) * nums.size() / 2 - sum;
}

void Leetcode268::test268() {
    vector<int> nums = {3, 0, 1};
    cout << missingNumber(nums) << " ,expected ans is 2." << endl;
}
