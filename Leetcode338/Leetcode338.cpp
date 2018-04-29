//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode338.h"

vector<int> Leetcode338::countBits(int num) {
    vector<int> dp(num + 1, 0);
    for (int i = 1; i <= num; ++i) {
        dp[i] = dp[i >> 1] + (i % 2);
    }
    return dp;
}
