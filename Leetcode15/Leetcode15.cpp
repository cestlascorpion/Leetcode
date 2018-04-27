//
// Created by cestl on 2018/4/27 0027.
//

#include "Leetcode15.h"

vector<vector<int>> Leetcode15::threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    if (nums.size() < 3)
        return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; ++i) {
        int target = -nums[i];
        int low = i + 1;
        int high = nums.size() - 1;

        while (low < high) {
            int sum = nums[low] + nums[high];
            if (sum < target)
                ++low;
            else if (sum > target)
                --high;
            else {
                vector<int> triplet(3, 0);
                triplet[0] = nums[i];
                triplet[1] = nums[low];
                triplet[2] = nums[high];
                ans.push_back(triplet);
                while (low < high && nums[low] == triplet[1])
                    ++low;
                while (low < high && nums[high] == triplet[2])
                    --high;
            }
        }
        while (i < nums.size() - 1 && nums[i + 1] == nums[i])
            ++i;
    }
    return ans;
}

