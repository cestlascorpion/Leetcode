//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode62.h"

int Leetcode62::uniquePaths(int m, int n) {
    double ans = 1.0;
    for (int i = 0; i < n - 1; ++i) {
        double x = m + i;
        double y = n - 1 - i;
        ans = ans * x / y;
    }
    return round(ans);
}

void Leetcode62::test62() {
    cout << uniquePaths(10, 10) << " == 28" << endl;
}
