#include "000.config.h"

class Solution {
public:
  vector<vector<int>> premutatuion(vector<int> &nums) {
    int begin = 0;
    int end = nums.size() - 1;
    vector<vector<int>> ans;
    if (begin >= end)
      return ans;
    premutatuionhelper(nums, begin, end, ans);
    return ans;
  }
  void premutatuionhelper(vector<int> nums, int begin, int end,
                          vector<vector<int>> &ans) {
    if (begin == end) {
      ans.push_back(nums);
      return;
    }
    for (int i = begin; i <= end; i++) {
      swap(nums[begin], nums[i]);
      premutatuionhelper(nums, begin + 1, end, ans);
      swap(nums[begin], nums[i]);
    }
  }
};
