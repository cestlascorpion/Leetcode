//
// Created by Wang on 2019/11/29.
//

#include "Leetcode506cn.h"

vector<string> Leetcode506cn::findRelativeRanks(vector<int> &nums) {
    auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) -> bool { return p1.first > p2.first; };
    set<pair<int, int>, decltype(cmp)> set(cmp);
    vector<string> res(nums.size(), "");
    for (int i = 0; i < nums.size(); ++i) {
        set.insert({nums[i], i});
    }
    int rank = 1;
    for (const auto &p : set) {
        if (rank == 1) {
            res[p.second] = "Gold Medal";
        } else if (rank == 2) {
            res[p.second] = "Silver Medal";
        } else if (rank == 3) {
            res[p.second] = "Bronze Medal";
        } else {
            res[p.second] = to_string(rank);
        }
        ++rank;
    }
    return res;
}
