#include "000.config.h"

class Solution
{
  public:
    int maximumProduct(vector<int> &nums)
    {
        int ans = 1;
        sort(nums.begin(), nums.end());
        if (nums[0] >= 0 || nums[nums.size() - 1] <= 0)
            return nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        else
        {
            int t1 = INT_MIN;
            if (nums[nums.size() - 3] >= 0)
                t1 = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
            int t2 = INT_MIN;
            if (nums[1] <= 0)
                t2 = nums[0] * nums[1] * nums[nums.size() - 1];
            return max(t1, t2);
        }
    }
};