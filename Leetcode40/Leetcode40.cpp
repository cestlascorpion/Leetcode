//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode40.h"

vector<vector<int>> Leetcode40::combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> res;
    sort(candidates.begin(), candidates.end());
    helper(candidates, res, 0, target, ans);
    return ans;
}

void Leetcode40::helper(vector<int> &candidates, vector<int> &res, int begin, int target,
                        vector<vector<int>> &ans) {
    if (target < 0) {
        return;
    } else if (target == 0) {
        ans.push_back(res);
        return;
    } else {
        for (int i = begin; i < candidates.size() && candidates[i] <= target; ++i) {
            res.push_back(candidates[i]);
            helper(candidates, res, i + 1, target - candidates[i], ans);
            res.pop_back();
            //避免出现重复的组合
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
                ++i;
        }
    }
}