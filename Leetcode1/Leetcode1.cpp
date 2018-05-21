//
// Created by hans on 18-4-24.
//

#include "Leetcode1.h"

vector<int> Leetcode1::twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    if (nums.size() < 2)
        return ans;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.find(target - nums[i]) == m.end()) {
            m[nums[i]] = i;
        } else {
            ans.push_back(m[target - nums[i]]);
            ans.push_back(i);
            break;
        }
    }
    return ans;
}

void Leetcode1::test1() {
    vector<int> nums = {2, 7, 11, 15};
    vector<int> ans = twoSum(nums, 9);
    for (auto item : ans)
        cout << item << " ";
    cout << endl;
}

