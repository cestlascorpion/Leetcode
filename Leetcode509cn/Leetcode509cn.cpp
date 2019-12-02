//
// Created by Wang on 2019/11/29.
//

#include "Leetcode509cn.h"
int Leetcode509cn::fib(int N) {
    vector<int> dp(N + 1, 0);
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[N];
}
