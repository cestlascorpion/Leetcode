#include "0.config.h"

class Solution
{
  public:
    int arrayPairSum(vector<int> &nums)
    {
        vector<int>::size_type nsize = nums.size(); //计算数组大小
        if (nsize == 0)
        { //如果大小为0，直接返回0
            return 0;
        }
        sort(nums.begin(), nums.end()); //排序
        int sum = 0;
        for (int i = 0; i < nsize; i += 2)
        { //计算两两一组中，数小的那个，和即为结果
            sum += nums[i];
        }
        return sum;
    }
};