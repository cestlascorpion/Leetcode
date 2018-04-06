#include "000.config.h"
class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
            ans = ans ^ nums[i];
        return ans;
    }
};
class Solution2
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        set<int> s(nums.begin(), nums.end());
        for (auto item : nums)
        {
            if (s.find(item) == s.end())
                return item;
            else
                s.erase(item);
        }
        return -1;
    }
};
class Solution3
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        if (nums.size() <= 0)
            return -1;

        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};