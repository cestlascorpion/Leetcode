#include "000.config.h"

class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() <= 0)
            return ans;
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
        for (int i = begin; begin < nums.size(); i++)
        {
            swap(nums[i], nums[begin]);
            backTrack(nums, begin + 1, ans);
            swap(nums[i], nums[begin]);
        }
    }
};
class Solution2
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;

        if (nums.empty())
            return ans;

        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()))
            ans.push_back(nums);

        return ans;
    }
};