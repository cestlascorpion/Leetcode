//
// Created by Wang on 2019/11/28.
//

#include "Leetcode447cn.h"

int Leetcode447cn::numberOfBoomerangs(vector<vector<int>> &points) {
    int res = 0;
    unordered_map<int, int> distance;
    for (const auto &p:points) {
        for (const auto &x:points) {
            if (p != x) {
                auto dis = (x[0] - p[0]) * (x[0] - p[0]) + (x[1] - p[1]) * (x[1] - p[1]);
                if (distance.find(dis) == distance.end()) {
                    res += distance[dis] * 2;
                }
                ++distance[dis];
            }
        }
        distance.clear();
    }
    return res;
}
