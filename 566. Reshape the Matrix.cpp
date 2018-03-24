#include "0. config.h"

class Solution
{
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        vector<vector<int>> ans;
        int m = nums.size();
        if (m < 1)
            return ans;
        int n = nums[0].size();
        if (n < 1)
            return ans;
        if (m * n != r * c)
            return nums;

        vector<int> s;
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                s.push_back(nums[row][col]);
                if (s.size() == c)
                {
                    ans.push_back(s);
                    s.clear();
                }
            }
        }
        return ans;
    }
};