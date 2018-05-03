//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode566.h"

vector<vector<int>> Leetcode566::matrixReshape(vector<vector<int>> &nums, int r, int c) {
    vector<vector<int>> ans;
    if (nums.empty() || nums[0].empty())
        return ans;
    int m = nums.size();
    int n = nums[0].size();
    if (m * n != r * c)
        return nums;

    vector<int> s;
    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            s.push_back(nums[row][col]);
            if (s.size() == c) {
                ans.push_back(s);
                s.clear();
            }
        }
    }
    return ans;
}
