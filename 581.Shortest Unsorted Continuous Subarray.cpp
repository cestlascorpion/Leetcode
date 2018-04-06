#include "000.config.h"

class Solution
{
  public:
    int findUnsortedSubarray2(vector<int>& nums)
	{
		vector<int> copy(nums);
		sort(copy.begin(),copy.end());
		int start = 0, end = nums.size() - 1;
		while (start < nums.size() && nums[start] == copy[start])
			start++;
		while (end>start && nums[end] == copy[end])
			end--;
		return end - start + 1;
	}
    int findUnsortedSubarray(vector<int> &nums)
    {
        const int N = (int)nums.size();
        // 先从两端向内找到第一个无序的位置
        int i = 0, j = N - 1;
        while (i < N - 1 && nums[i] <= nums[i + 1])
            i++;
        while (j > 0 && nums[j - 1] <= nums[j])
            j--;
        if (i >= j)
            return 0;
        // 在nums[i..j]中找到minNum和maxNum
        int minNum = INT_MAX, maxNum = INT_MIN;
        for (int k = i; k <= j; k++)
        {
            minNum = min(minNum, nums[k]);
            maxNum = max(maxNum, nums[k]);
        }
        // 根据nums[i-1]<=minNum、nums[j+1]>=maxNum向外扩展
        while (i >= 1 && nums[i - 1] > minNum)
            i--;
        while (j < N - 1 && nums[j + 1] < maxNum)
            j++;

        return j - i + 1;
    }
};