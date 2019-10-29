//
// Created by Wang on 2019/10/31.
//

#include "Leetcode276cn.h"

int Leetcode276cn::numWays(int n, int k) {
    if (n == 0 || k == 0) {
        return 0;
    }
    if (n == 1) {
        return k;
    }

    int k1 = k;
    int k2 = k * k;
    for (int i = 2; i < n; ++i) {
        int tmp = k2 * (k - 1) + k1 * (k - 1);
        k1 = k2;
        k2 = tmp;
    }
    return k2;
}
