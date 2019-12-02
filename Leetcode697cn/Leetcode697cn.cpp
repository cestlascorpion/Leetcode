//
// Created by Wang on 2019/12/2.
//

#include "Leetcode697cn.h"

int Leetcode697cn::findShortestSubArray(vector<int> &nums) {
    map<int, info> map;
    for (int i = 0; i < nums.size(); ++i) {
        auto iter = map.find(nums[i]);
        if (iter == map.end()) {
            map[nums[i]] = {1, i, -1};
        } else {
            ++map[nums[i]].count;
            map[nums[i]].last = i;
        }
    }
    int max = 0;
    vector<info> max_info;
    for (const auto &pair : map) {
        if (pair.second.count > max) {
            max = pair.second.count;
            max_info.clear();
            max_info.push_back(pair.second);
        } else if (pair.second.count == max) {
            max_info.push_back(pair.second);
        } else {
            continue;
        }
    }
    if (max_info.empty()) {
        return 0;
    }
    int min = INT32_MAX;
    for (const auto &info : max_info) {
        if (info.last > -1)
            min = std::min(min, info.last - info.first + 1);
    }
    return min == INT32_MAX ? 0 : min;
}
