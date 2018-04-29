//
// Created by hans on 4/29/18.
//

#include "Leetcode46.h"

vector<vector<int>> Leetcode46::permute(vector<int> &nums) {
    vector<vector<int>> ans;
    if (nums.empty())
        return ans;

    helper(nums, 0, nums.size() - 1, ans);
    return ans;
}

void Leetcode46::helper(vector<int> nums, int begin, int end, vector<vector<int>> &ans) {
    if (begin > end) {
        ans.push_back(nums);
        return;
    }
    for (int i = begin; i <= end; ++i) {
        swap(nums[i], nums[begin]);
        helper(nums, begin + 1, end, ans);
        swap(nums[i], nums[begin]);
    }
}

vector<vector<int>> Leetcode46::permute2(vector<int> &nums) {
    vector<vector<int>> ans;

    if (nums.empty())
        return ans;

    sort(nums.begin(), nums.end());
    ans.push_back(nums);
    while (next_permutation(nums.begin(), nums.end()))
        ans.push_back(nums);

    return ans;
}

void Leetcode46::test46() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for (auto item:ans) {
        for (auto jtem:item) {
            cout << jtem << " ";
        }
        cout << endl;
    }
    cout << endl;
}
