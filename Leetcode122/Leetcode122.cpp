//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode122.h"

int Leetcode122::maxProfit(vector<int> &prices) {
    int ans = 0;
    if (prices.size() < 2)
        return ans;
    for (int i = 0; i < prices.size() - 1; i++) {
        int delta = prices[i + 1] - prices[i];
        ans += (delta > 0 ? delta : 0);
    }
    return ans;
}
