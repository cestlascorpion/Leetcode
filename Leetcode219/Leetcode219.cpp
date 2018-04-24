//
// Created by hans on 18-4-23.
//

#include "Leetcode219.h"

void Leetcode219::test219() {
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};
    if (containsDuplicate(nums1) == true && containsDuplicate(nums2) == false)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

bool Leetcode219::containsDuplicate(vector<int> &nums) {
    if (nums.empty())
        return false;
    unordered_set<int> ans(nums.begin(), nums.end());
    if (nums.size() > ans.size())
        return true;
    return false;
}
