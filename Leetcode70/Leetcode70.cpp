//
// Created by hans on 4/27/18.
//

#include "Leetcode70.h"

int Leetcode70::climbStairs(int n) {
    if (n <= 2)
        return n;
    int onestep = 1;
    int twostep = 2;
    int ans = 0;
    for (int i = 3; i <= n; ++i) {
        ans = onestep + twostep;
        onestep = twostep;
        twostep = ans;
    }
    return ans;
}

void Leetcode70::test70() {
    cout << "step->4 = 5 , output is " << climbStairs(4) << endl;
    cout << "step->5 = 8 , output is " << climbStairs(5) << endl;
}
