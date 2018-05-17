//
// Created by hans on 5/17/18.
//

#include "Leetcode18.h"

vector<vector<int>> Leetcode18::fourSum(vector<int> &nums, int target) {
    vector<vector<int>> ans;
    if (nums.empty() || nums.size() < 4)
        return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; ++i) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j == (i + 1) || nums[j] != nums[j - 1]) {
                    int begin = j + 1;
                    int end = nums.size() - 1;
                    int tar = target - nums[i] - nums[j];
                    while (begin < end) {
                        if (nums[begin] + nums[end] == tar) {
                            vector<int> tmp{nums[i], nums[j], nums[begin], nums[end]};
                            ans.emplace_back(tmp);
                            while (begin < end && nums[begin] == nums[begin + 1]) ++begin;
                            while (begin < end && nums[end] == nums[end - 1])--end;
                            ++begin;
                            --end;
                        } else if (nums[begin] + nums[end] > tar) {
                            --end;
                        } else {
                            ++begin;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

void Leetcode18::test18() {
    vector<int> nums{1, 0, -1, 0, -2, 2};
    auto ans = fourSum(nums, 0);
    for (auto item:ans) {
        for (auto jtem: item) {
            cout << jtem << " ";
        }
        cout << endl;
    }
}
