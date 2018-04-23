#include "000.config.h"

class Solution
{
  public:
    bool containsDuplicate(vector<int> &nums)
    {
        if (nums.size() <= 0)
            return false;
        unordered_set<int> set(nums.begin(), nums.end());
        return nums.size() != set.size();
    }
};