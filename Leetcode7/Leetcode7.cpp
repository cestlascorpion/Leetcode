//
// Created by hans on 4/25/18.
//

#include "Leetcode7.h"

int Leetcode7::reverse(int x) {
    bool negative = x < 0;
    if (negative)
        x = -x;
    long ans = 0;
    while (x) {
        ans = ans * 10 + x % 10;
        x = x / 10;
    }
    if (negative)
        ans = -ans;
    if (ans > INT32_MAX || ans < INT32_MIN)
        return 0;
    return (int) ans;
}

void Leetcode7::test7() {
    int x = -123;
    cout << reverse(x) << endl;
    int y = -120;
    cout << reverse(y) << endl;
}
