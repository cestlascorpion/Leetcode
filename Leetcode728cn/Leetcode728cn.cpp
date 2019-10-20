//
// Created by Wang on 2019/10/20.
//

#include "Leetcode728cn.h"

vector<int> Leetcode728cn::selfDividingNumbers(int left, int right) {
    vector<int> rslt;
    for (int n = left; n <= right; n++) {
        if (isSelfDividing(n))
            rslt.push_back(n);
    }
    return rslt;
}
bool Leetcode728cn::isSelfDividing(int n) {
    int x = n;
    while (x) {
        int d = x % 10;
        if (d == 0)
            return false;
        if (n % d != 0)
            return false;
        x = x / 10;
    }
    return true;
}
