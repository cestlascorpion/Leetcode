#include "000.config.h"

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        int len = nums.size();
        if (len < 1)
            return 0;

        int res = 0;
        int ans = nums.at(0);
        for (int i = 0; i < nums.size(); i++)
        {
            res += nums.at(i);
            ans = max(ans, res);
            res = max(res, 0);
        }
        return ans;
    }
};