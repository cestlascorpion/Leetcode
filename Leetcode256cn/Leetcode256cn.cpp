//
// Created by Wang on 2019/10/30.
//

#include "Leetcode256cn.h"

int Leetcode256cn::minCost(vector<vector<int>> &costs) {
    if (costs.empty()) {
        return 0;
    }
    int min_r = 0;
    int min_b = 0;
    int min_g = 0;
    int res;
    for (const auto & cost : costs) {
        res = INT_MAX;
        int tmp_min_r = std::min(min_b, min_g) + cost[0];
        res = std::min(tmp_min_r, res);
        int tmp_min_b = std::min(min_r, min_g) + cost[1];
        res = std::min(tmp_min_b, res);
        int tmp_min_g = std::min(min_r, min_b) + cost[2];
        res = std::min(tmp_min_g, res);
        min_r = tmp_min_r;
        min_b = tmp_min_b;
        min_g = tmp_min_g;
    }
    return res;
}
