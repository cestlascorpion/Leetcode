/* 121. Best Time to Buy and Sell Stock
 * 找到最大差值，且减数位于被减数之前 
 * For example:、
 * [1,2,3,4] ==> returns 3 (buy at 1 and sell at 4)
 * [4,3,2,1] ==> returns 0 (don't buy)
 * [4,10,25,2,10] ==> returns 21 (buy at 4 and sell at 25)
 * 在从前到后的遍历过程中，不断更新min和delta
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
        for(int i = 0; i < prices.size(); i ++)
        {
            min = prices.at(i) < min ? prices.at(i) : min;
            res = prices.at(i) - min > res ? prices.at(i) - min : res;
         }
        return res;
    }
};