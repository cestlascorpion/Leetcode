//
// Created by Wang on 2019/10/13.
//

#include "Leetcode7cn.h"

int Leetcode7cn::reverse(int x) {
    int res = 0;
    while (x != 0) {
        if (overflow(res)) return 0;
        int bit = x % 10;
        res = res * 10 + bit;
        x = x / 10;
    }
    return res;
}

int Leetcode7cn::overflow(int x) {
    return x > INT_MAX / 10 || x < INT_MIN / 10;
}
