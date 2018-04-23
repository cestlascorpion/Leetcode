#include "000.config.h"

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        if (prices.size() < 2)
            return ans;
        for (int i = 0; i < prices.size() - 1; i++)
            ans += (prices[i + 1] - prices[i] > 0 ? prices[i + 1] - prices[i] : 0);
        return ans;
    }
};