//
// Created by Wang on 2019/10/14.
//

#include "Leetcode475cn.h"

// [1,2,3],[2]
int Leetcode475cn::findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(heaters.begin(), heaters.end());
    int res = INT_MIN;
    for (const auto &house:houses) {
        int distance = cal_distance(house, heaters);
        cout << distance << endl;
        res = std::max(res, distance);
    }
    return res;
}

int Leetcode475cn::cal_distance(int point, vector<int> &pos) {
    // 1 3 5
    auto iter = lower_bound(pos.begin(), pos.end(), point);
    // 6, 7 -> end()
    if (iter == pos.end()) {
        return point - pos.back();
    }
    // 1 2 3 4 5 -> pos: 0 1 1 2 2 *pos >= point
    int res = *iter - point;
    if (res == 0) return 0; // 1 3 5 = -> 0
    // 2 4 -> pos 1 2 *pos 3 5
    if (iter != pos.begin()) {
        --iter; // *pos < point
        res = std::min(res, point - *iter);
    }
    return res;
}
