#include "000.config.h"

class Solution
{
  public:
    void moveZeroes(vector<int> &nums)
    {
        for (int i = 0, j = 0; j < nums.size(); j++) //慢指针指向第一个零元素 快指针指向慢指针以后的第一个非零元素
        {
            if (nums[j] != 0) //num[j]指向[i,j]之间的0时，不移动i，只移动j，直到第一个非零元素
            {
                if (i != j)
                {
                    nums[i] = nums[j];
                    nums[j] = 0;
                }
                i++;
            }
        }
    }
};