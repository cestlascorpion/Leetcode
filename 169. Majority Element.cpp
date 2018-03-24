#include "0. config.h"
class Solution
{
public:
	int majorityElement(vector<int> &nums)
	{
		int count = 0;
		int res;
		for (int i = 0; i < nums.size(); i++)
		{
			if (count == 0)
				res = nums[i];
			count += (nums[i] == res ? 1 : -1);
		}
		return res;
	}
};