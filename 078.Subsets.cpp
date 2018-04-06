#include "000.config.h"

class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> subset;
        dfsHelper(subset, 0, nums, ans);
        return ans;
    }
    void dfsHelper(vector<int> &curset, int startIndex, vector<int> &nums, vector<vector<int>> &ans)
    {
        ans.push_back(curset);
        for (int i = startIndex; i < nums.size(); i++)
        {
            curset.push_back(nums[i]);
            dfsHelper(curset, i + 1, nums, ans);
            curset.pop_back();
        }
    }
};