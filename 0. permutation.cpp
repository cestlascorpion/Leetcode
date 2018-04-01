#include "0. config.h"

class Solution
{
public:
  vector<vector<int>> premutatuion(vector<int> &nums)
  {
    int begin = 0;
    int end = nums.size() - 1;
    vector<vector<int>> ans;
    if (begin >= end)
      return ans;
    for (int i = begin; i <= end; i++)
    {
      if (isValid(nums, begin, i))
      {
        swap(nums[begin], nums[i]);
        permutationHelper(nums, i, ans);
        swap(nums[begin], nums[i]);
      }
    }
  }
  bool isValid(vector<int> &nums, int start, int index)
  {
    // return nums[start] != nums[index];
    return true;
  }
  void permutationHelper(vector<int> &nums, int i, vector<vector<int>> &ans) {}
};