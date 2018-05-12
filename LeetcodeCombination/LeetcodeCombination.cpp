//
// Created by cestl on 2018/5/13 0013.
//

#include "LeetcodeCombination.h"

vector<vector<int>> LeetcodeCombination::Combination(vector<int> nums) {
    vector<vector<int>> ans;
    if (nums.empty())
        return ans;
    vector<int> cur;
    helper(cur, 0, nums.size() - 1, nums, ans);
    return ans;
}

void LeetcodeCombination::helper(vector<int> &cur, int begin, int end,
                                 vector<int> &nums, vector<vector<int>> &ans) {
    if (begin > end)
        return;
    for (int i = begin; i <= end; ++i) {
        cur.push_back(nums[i]);
        ans.push_back(cur);
        helper(cur, i + 1, end, nums, ans);
        cur.pop_back();
    }
}


void LeetcodeCombination::testCombination() {
    vector<int> nums{1, 2, 3};
    auto ans = Combination(nums);
    for (auto item:ans) {
        for (auto jtem:item) {
            cout << jtem << " ";
        }
        cout << endl;
    }
}
