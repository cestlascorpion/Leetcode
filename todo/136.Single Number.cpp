#include "000.config.h"

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            result ^= nums[i];
        }
        return result;
        /*
        map<int,int> mapDog;
        map<int,int>::iterator it = mapDog.begin();
        for(int i = 0; i != nums.size(); i++)
        {
            it = mapDog.find(nums.at(i));
            if( it == mapDog.end())
                mapDog[nums.at(i)] = 1;  
            else
                mapDog.erase(it);
        }
        it = mapDog.begin();
        return it->first;
        */
    }
};