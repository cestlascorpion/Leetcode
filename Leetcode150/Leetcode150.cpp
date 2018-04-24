//
// Created by hans on 18-4-23.
//

#include "Leetcode150.h"

void Leetcode150::test150() {
    vector<int> v1 = {7, 1, 5, 3, 6, 4};
    vector<int> v2 = {1, 2, 3, 4, 5};
    cout << maxProfit(v1) << " == 7?" << endl
         << maxProfit(v2) << " == 4?" << endl;
}

int Leetcode150::maxProfit(vector<int> &prices) {
    int ans = 0;
    for (int i = 1; i < prices.size(); ++i) {
        ans += prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0;
    }
    return ans;
}
