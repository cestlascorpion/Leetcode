#include "000.config.h"

class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high)
        {
            while (low < high && nums[low] != val)
                low++;
            //左起第一个待交换的值
            while (low < high && nums[high] == val)
                high--;
            swap(nums[low], nums[high]);
        }
        if (low == nums.size() - 1 && nums[low] != val)
            return nums.size();
        return low;
    }
};