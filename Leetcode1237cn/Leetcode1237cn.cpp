//
// Created by Wang on 2019/11/7.
//

#include "Leetcode1237cn.h"
vector<vector<int>> Leetcode1237cn::findSolution(CustomFunction &customfunction, int z) {
    int l = 1, h = 1000;
    vector<vector<int>> res;
    while (l < h) {
        if (customfunction.f(l, h) == z) {
            res.push_back({l, h});
            l++;
            h--;
        } else if (customfunction.f(l, h) < z) {
            l++;
        } else
            h--;
    }
    l = 1;
    h = 1000;
    while (l < h) {
        if (customfunction.f(h, l) == z) {
            res.push_back({h, l});
            l++;
            h--;
        } else if (customfunction.f(h, l) < z) {
            l++;
        } else
            h--;
    }
    if (customfunction.f(l, h) == z && l == h)
        res.push_back({l, h});
    return res;
}
