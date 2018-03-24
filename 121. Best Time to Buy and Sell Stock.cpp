#include "0.config.h"

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        /*
        int i, j;
        int res = 0;
        for(i = 0; i < prices.size(); i ++)
        {
            for(j = i + 1; j < prices.size(); j ++)
            {
                int delta = prices.at(j) - prices.at(i);
                if(delta > res)
                    res = delta;
            }
        }
        return res;
        */
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