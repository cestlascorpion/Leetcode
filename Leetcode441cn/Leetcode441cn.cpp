//
// Created by Wang on 2019/11/27.
//

#include "Leetcode441cn.h"

int Leetcode441cn::arrangeCoins(int n) {
    int sum = 0;
    int res = 0;
    while (true) {
        sum += res;
        if (n - sum < res + 1) {
            return res;
        }
        ++res;
    }
}
