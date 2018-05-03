//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode322.h"


int Leetcode322::coinChange(vector<int> &coins, int amount) {
    if (coins.empty() || amount <= 0)
        return 0;
    vector<int> helper(amount + 1, -1);
    helper[0] = 0;
    sort(coins.begin(), coins.end());
    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < coins.size() && i - coins[j] >= 0; ++j) {
            if (helper[i - coins[j]] >= 0)
                if (helper[i] >= 0)
                    helper[i] = min(helper[i], 1 + helper[i - coins[j]]);
                else
                    helper[i] = 1 + helper[i - coins[j]];
        }
    }
    return helper[amount];
}

int Leetcode322::coinChangeMethods(vector<int> &coins, int amount) {
    if (coins.empty() || amount <= 0)
        return 0;
    vector<int> helper(amount + 1, 0);
    helper[0] = 1;
    for (int i = 0; i < coins.size(); ++i) {
        for (int j = coins[i]; j <= amount; ++j) {
            helper[j] += helper[j - coins[i]];
        }
    }
    if (helper[amount] == 0)
        return -1;
    else
        return helper[amount];

}

void Leetcode322::test322() {
    vector<int> coins = {3};
    int amount = 2;
    //cout << coinChangeMethods(coins, amount) << " == 11?" << endl;
    cout << coinChange(coins, amount) << " == 11?" << endl;
}

