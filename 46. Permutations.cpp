#include "0. config.h"

class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n <= 0)
            return ans;
        vector<int> v;
        helper(nums, 0, ans);
        return ans;
    }
    void helper(vector<int> &nums, int begin, vector<vector<int>> &ans)
    {
        if (begin >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++)
        {
            swap(nums[begin, nums[i]]);
            helper(nums.begin + 1, ans);
            swap(nums[begin, nums[i]]);
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