//
// Created by Wang on 2019/12/19.
//

#include "Leetcode970cn.h"

vector<int> Leetcode970cn::powerfulIntegers(int x, int y, int bound) {
    set<int> s;
    for (int i = 1; i < bound; i *= x) {
        for (int j = 1; i + j <= bound; j *= y) {
            s.insert(i + j);
            if (y == 1)
                break;
        }
        if (x == 1)
            break;
    }
    return vector<int>(s.begin(), s.end());
}

vector<int> Leetcode970cn::powerfulIntegers2(int x, int y, int bound) {
    vector<int> xs;
    xs.push_back(1);
    while (x != 1 && xs.back() * x < bound) {
        xs.push_back(xs.back() * x);
    }
    vector<int> ys;
    ys.push_back(1);
    while (y != 1 && ys.back() * y < bound) {
        ys.push_back(ys.back() * y);
    }
    set<int> s;
    for (const auto &x : xs) {
        for (const auto &y : ys) {
            int tmp = x + y;
            if (tmp <= bound) {
                s.insert(tmp);
            } else {
                break;
            }
        }
    }
    return vector<int>(s.begin(), s.end());
}
