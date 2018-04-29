//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode39.h"

vector<vector<int>> Leetcode39::combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> res;
    sort(candidates.begin(), candidates.end());
    helper(candidates, res, 0, target, ans);
    return ans;
}

void Leetcode39::helper(vector<int> &candidates, vector<int> &res, int begin, int target,
                        vector<vector<int>> &ans) {
    if (target < 0) {
        return;
    } else if (target == 0) {
        ans.push_back(res);
        return;
    } else {
        for (int i = begin; i < candidates.size() && candidates[i] <= target; ++i) {
            res.push_back(candidates[i]);
            //begin(i)没有增加是因为数字可以无限制重复取用，所以进入递归调用后仍然可以选择candidates[i]
            helper(candidates, res, i, target - candidates[i], ans);
            res.pop_back();
        }
    }
}
