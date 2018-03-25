#include "0. config.h"

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        int min = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            min = prices.at(i) < min ? prices.at(i) : min;
            res = prices.at(i) - min > res ? prices.at(i) - min : res;
        }
        return res;
    }
};