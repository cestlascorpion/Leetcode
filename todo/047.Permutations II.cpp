#include "000.config.h"

class Solution
{
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() <= 0)
            return ans;
        sort(nums.begin(), nums.end());
        backTrack(nums, 0, ans);
        return ans;
    }
    void backTrack(vector<int> nums, int begin, vector<vector<int>> &ans)
    {
        if (begin == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++)
        {
            if (i != begin && nums[i] == nums[begin])
                continue;
            swap(nums[i], nums[begin]);
            backTrack(nums, begin + 1, ans);
        }
    }
};
class Solution2
{
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        set<vector<int>> myset;

        if (nums.size() <= 0)
            return ans;
        backTrack(nums, 0, myset);
        return ans;
    }
    void backTrack(vector<int> nums, int begin, set<vector<int>> &myset)
    {
        if (begin == nums.size())
        {
            myset.insert(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++)
        {
            swap(nums[i], nums[begin]);
            backTrack(nums, begin + 1, myset);
            swap(nums[i], nums[begin]);
        }
    }
};