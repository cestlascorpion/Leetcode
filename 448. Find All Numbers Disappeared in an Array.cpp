/* 448. Find All Numbers Disappeared in an Array
 * 数组长度 [1，N] 存储的数值[1,N] 将(数值-1)即可对应数值的下标
 * 将(数值-1)作为索引将数组中对应位置的数值取相反数
 * 数组中数值仍为正值，则表示没有索引到，即可返回(索引+1)
 */
#include "0. config.h"

class Solution
{
  public:
	vector<int> findDisappearedNumbers(vector<int> &nums)
	{
		/*
		map<int, int> mymap;
		map<int, int>::iterator it;
		vector<int> result;
		for (int i = 0; i != nums.size(); i++)
		{
			it = mymap.find(nums.at(i));
			if (it == mymap.end())
			{
				mymap[nums.at(i)] = i;
			}
		} 
		int count = 0;
		for (int i = 1; count != nums.size() - mymap.size() && i <= nums.size(); i++)
		{
			if (mymap.find(i) == mymap.end())
			{
				result.push_back(i);
				count++;
			}
		}
		return result;
        */
		vector<int> result;
		int len = nums.size();
		int index;
		for (int i = 0; i < len; i++)
		{
			index = abs(nums.at(i)) - 1;
			nums.at(index) = nums.at(index) > 0 ? -nums.at(index) : nums.at(index);
		}
		for (int i = 0; i < len; i++)
		{
			if (nums.at(i) > 0)
				result.push_back(i + 1);
		}
		return result;
	}
};