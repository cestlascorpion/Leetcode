//
// Created by Wang on 2019/10/13.
//

#include "Leetcode625cn.h"

int Leetcode625cn::smallestFactorization(int a) {
    if (a < 0) {
        return 0;
    }
    if (a < 10) {
        return a;
    }

    vector<char> bit;
    for (int i = 9; i > 1; --i) {
        while (a % i == 0) {
            a = a / i;
            bit.push_back(i);
        }
    }
    if (a != 1) {
        return 0;
    }
    int res = 0;
    for (auto iter = bit.rbegin(); iter != bit.rend(); ++iter) {
        if(res > INT_MAX / 10) return 0;
        res = res * 10 + *iter;
    }
    return res;
}
