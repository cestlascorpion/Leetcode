//
// Created by Wang on 2019/12/2.
//

#include "Leetcode645cn.h"

typedef continuel continuel;
vector<int> Leetcode645cn::findErrorNums(vector<int> &nums) {
    vector<int> res(2, 0);
    vector<int> helper(nums.size(), 0);
    for (const auto &num : nums) {
        if (helper[num - 1] != 0) {
            res[0] = num;
        }
        helper[num - 1] = num;
    }
    for (int i = 0; i < helper.size(); ++i) {
        if (helper[i] == 0) {
            res[1] = i + 1;
        }
    }
    return res;
}
vector<int> Leetcode645cn::findErrorNums2(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(2, 0);
    vector<int> temp(n, 0);
    for (int i = 0; i < n; i++) {
        temp[nums[i] - 1]++;
        if (temp[nums[i] - 1] == 2) {
            res[0] = nums[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (temp[i] == 0) {
            res[1] = i + 1;
            break;
        }
    }
    return res;
}
