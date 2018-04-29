//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode47.h"

vector<vector<int>> Leetcode47::permuteUnique(vector<int> &nums) {
    vector<vector<int>> ans;
    if (nums.size() <= 0)
        return ans;
    sort(nums.begin(), nums.end());
    helper(nums, 0, ans);
    return ans;
}

void Leetcode47::helper(vector<int> nums, int begin, vector<vector<int>> &ans) {
    if (begin == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int i = begin; i < nums.size(); i++) {
        //使用 预排序，值传递，交换后不放回，对重复的数字直接剪枝
        if (i != begin && nums[i] == nums[begin])
            continue;
        swap(nums[i], nums[begin]);
        helper(nums, begin + 1, ans);
    }
}

void Leetcode47::helper2(vector<int> &nums, int begin, vector<vector<int>> &ans) {
    if (begin == nums.size()) {
        ans.push_back(nums);
        return;
    }
    set<int> s(nums.begin(), nums.end());
    for (int i = begin; i < nums.size(); ++i) {
        if (s.find(nums[i]) != s.end()) {
            swap(nums[i], nums[begin]);
            helper(nums, begin + 1, ans);
            swap(nums[i], nums[begin]);
            s.erase(nums[i]);
        }
    }
}

void Leetcode47::test47() {
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> ans = permuteUnique(nums);
    for (auto item:ans) {
        for (auto jtem:item) {
            cout << jtem << " ";
        }
        cout << endl;
    }
    cout << endl;
}
