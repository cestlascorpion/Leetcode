//
// Created by hans on 4/27/18.
//

#include "Leetcode121.h"

int Leetcode121::maxProfit(vector<int> &prices) {
    if (prices.empty())
        return 0;
    int ans = 0;
    int minp = INT32_MAX;
    for (auto item:prices) {
        minp = min(minp, item);
        ans = max(ans, item - minp);
    }
    return ans;
}

void Leetcode121::test121() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "asn = " << maxProfit(prices) << endl;
}
