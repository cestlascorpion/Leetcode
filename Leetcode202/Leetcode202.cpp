//
// Created by cestl on 2018/5/4 0004.
//

#include "Leetcode202.h"

bool Leetcode202::isHappy(int n) {
    while (n != 1) {
        if (s.find(n) != s.end())
            return false;
        int m = 0;
        while (n) {
            int x = n % 10;
            n = n / 10;
            m += x * x;
        }
        n = m;
    }
    return true;
}

void Leetcode202::test202() {
    for (int i = 101; i <= 120; ++i) {
        cout << i << " -> " << isHappy(i) << endl;
    }
}
