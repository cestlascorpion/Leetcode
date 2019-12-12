//
// Created by Wang on 2019/12/12.
//

#include "Leetcode1029cn.h"

int Leetcode1029cn::twoCitySchedCost(vector<vector<int>> &costs) {
    vector<pair<int, int>> cost(costs.size());
    for (int i = 0; i < costs.size(); ++i) {
        cost[i].first = costs[i][0] - costs[i][1];
        cost[i].second = i;
    }
    auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) -> bool { return p1.first < p2.first; };
    sort(cost.begin(), cost.end(), cmp);
    // 前10 -> A 后10 -> B
    int res = 0;
    for (int i = 0; i < costs.size() / 2; ++i) {
        res += costs[cost[i].second][0];
        res += costs[cost[i + cost.size() / 2].second][1];
    }
    return res;
}
