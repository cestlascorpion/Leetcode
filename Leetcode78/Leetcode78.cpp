//
// Created by hans on 4/29/18.
//

#include "Leetcode78.h"

vector<vector<int>> Leetcode78::subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    if (nums.empty())
        return ans;
    vector<int> curset;
    helper(curset, 0, nums.size() - 1, nums, ans);
    return ans;
}

void Leetcode78::helper(vector<int> &curset, int begin, int end,
                        vector<int> &nums, vector<vector<int>> &ans) {
    ans.push_back(curset);
    for (int i = begin; i <= end; ++i) {
        curset.push_back(nums[i]);
        helper(curset, i + 1, end, nums, ans);
        curset.pop_back();
    }
}
