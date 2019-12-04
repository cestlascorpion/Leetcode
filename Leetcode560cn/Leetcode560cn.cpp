//
// Created by Wang on 2019/12/4.
//

#include "Leetcode560cn.h"
// 1, 1, 1
// x  x  x
int Leetcode560cn::subarraySum(vector<int> &nums, int k) {
    int res = 0;
    vector<int> sum(nums.size(), 0);
    for (int len = 0; len < nums.size(); ++len) {
        for (int i = 0; i < sum.size(); ++i) {
            if (i + len == nums.size())
                break;
            sum[i] += nums[i + len];
            if (sum[i] == k) {
                ++res;
            }
        }
    }
    return res;
}

int Leetcode560cn::subarraySum2(vector<int> &nums, int k) {
    int res = 0;
    int cur = 0;
    map<int, int> map;
    map[0] = 1;
    for (const auto &num : nums) {
        cur += num;
        res += (map.find(cur - k) == map.end() ? 0 : map[cur - k]);
        ++map[cur];
    }
    return res;
}
