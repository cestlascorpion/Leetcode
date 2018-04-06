#include "000.config.h"

class Solution
{
  public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        if (nums.size() < 1)
            return 0;

        int ans = 0;
        int cnt = 0;
        int i = 0;
        while (i < nums.size())
        {
            while (nums[i] != 1 && i < nums.size())
                i++;
            while (nums[i] == 1 && i < nums.size())
            {
                cnt++;
                i++;
            }
            ans = cnt > ans ? cnt : ans;
            cnt = 0;
        }
        return ans;
    }
};