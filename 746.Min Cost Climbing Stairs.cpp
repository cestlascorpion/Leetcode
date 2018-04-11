#include "000.config.h"

class Solution
{
  public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int ans = 0;
        int pre1 = 0;
        int pre2 = 0;
        for (int i = 2; i < cost.size(); i++)
        {
            ans = min(pre1 + cost[i - 1], pre2 + cost[i - 2]);
            pre2 = pre1;
            pre1 = ans;
        }
        return ans;
    }
    int minCostClimbingStairs2(vector<int> &cost)
    {
        vector<int> ans(cost.size(), 0);
        for (int i = 2; i < cost.size(); i++)
        {
            ans[i] = min(ans[i - 1] + cost[i - 1], ans[i - 2] + cost[i - 2]);
        }
        /*
        for (auto e : ans)
            cout << e << "\t";
        cout << endl;
        */
        return ans[cost.size() - 1];
    }
};