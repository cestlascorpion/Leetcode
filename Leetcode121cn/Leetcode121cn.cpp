//
// Created by Wang on 2019/10/13.
//

#include "Leetcode121cn.h"

int Leetcode121cn::maxProfit(vector<int> &prices) {
    if (prices.empty()) {
        return 0;
    }
    int res = INT_MIN;
    int min = INT_MAX;
    // [7,1,5,3,6,4]
    // res 0 0 4 4 5 5
    // min 7 1 1 1 1 1
    for (int i = 0; i < prices.size(); ++i) {
        min = std::min(min, prices[i]);
        res = std::max(prices[i] - min, res);
    }
    return res;
}
