//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode448.h"

vector<int> Leetcode448::findDisappearedNumbers(vector<int> &nums) {
    vector<int> ans;
    int index;
    for (int i = 0; i < nums.size(); i++) {
        index = abs(nums[i]) - 1;
        nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0)
            ans.push_back(i + 1);
    }
    return ans;
}

vector<int> Leetcode448::findDisappearedNumbers2(vector<int> &nums) {
    vector<int> ans;
    map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]] = i;
    }
    int count = 0;
    for (int i = 1; count < nums.size() - map.size() && i <= nums.size(); ++i) {
        if (map.find(i) == map.end()) {
            ans.push_back(i);
            ++count;
        }
    }
    return ans;
}

void Leetcode448::test448() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = findDisappearedNumbers(nums);
    for (auto item : ans)
        cout << item << " ";
    cout << endl;
}
