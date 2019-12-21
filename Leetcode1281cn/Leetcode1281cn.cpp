//
// Created by Wang on 2019/12/21.
//

#include "Leetcode1281cn.h"

int Leetcode1281cn::subtractProductAndSum(int n) {
    if (n == 0)
        return 0;

    int multi = 1;
    int sum = 0;
    while (n > 0) {
        multi = multi * (n % 10);
        sum = sum + (n % 10);
        n = n / 10;
    }
    return multi - sum;
}
