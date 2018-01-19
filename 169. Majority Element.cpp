/* 169. Majority Element
 * A A A C C B B C C C B C C
 * 1 2 3 2 1 1 2 1 1 2 1 2 3
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
		/*
		int len = nums.size();
		sort(nums.begin(), nums.end());
		int i, j;
		for(i = 0, j = 0; j < len; j ++)
		{
		int temp = nums[i];
		if(nums[j] != nums[i])
		{
		if(2*(j - i) > len)
		break;
		else
		{
		while(nums[i] == temp)
		{
		i ++;
		}
		j = i;
		}
		}
		}
		return nums[i];
		*/
		/*
		int len = nums.size();
		sort(nums.begin(), nums.end());
		return nums[len/2];
		*/
        /*
		map<int, int> helpMap;
		for (int i = 0; i < nums.size(); i++)
		{
			if (helpMap.find(nums[i]) == helpMap.end())
				helpMap[nums[i]] = 1;
			else
			{
				helpMap[nums[i]]++;
				if (helpMap[nums[i]]>nums.size() / 2)
					return nums[i];
			}
		}
        return nums[0];
        */
        
        int count = 0;
        int res;
        for (int i = 0; i < nums.size(); i++)
        {
            if(count == 0)
                res = nums[i];
            count += (nums[i]==res?1:-1);
        }
        return res;
        
	}
};