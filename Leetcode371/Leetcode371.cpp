//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode371.h"

int Leetcode371::getSum(int a, int b) {
    if (b == 0)
        return a;
    int sum = a ^b;
    int carry = (a & b) << 1;
    return getSum(sum, carry);
}

void Leetcode371::test371() {
    int a = 5;
    int b = 7;
    int sum = getSum(a, b);
    cout << a << "+" << b << "=" << sum << endl;
}
