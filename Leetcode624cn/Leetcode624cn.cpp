//
// Created by Wang on 2019/12/12.
//

#include "Leetcode624cn.h"

int Leetcode624cn::maxDistance(vector<vector<int>> &arrays) {
    int res = 0;
    int min = arrays[0].front();
    int max = arrays[0].back();
    for (int i = 1; i < arrays.size(); ++i) {
        int tmp = std::max(abs(arrays[i].front() - max), abs(arrays[i].back() - min));
        res = std::max(res, tmp);
        min = std::min(min, arrays[i].front());
        max = std::max(max, arrays[i].back());
    }
    return res;
}
