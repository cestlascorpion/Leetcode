#include "0. config.h"

class Solution
{
  public:
    int distributeCandies(vector<int> &candies)
    {
        if (candies.size() % 2 != 0)
            return 0;
        unordered_map<int, int> HASH;
        int res = 0;
        for (int c : candies)
        {
            HASH[c]++;
            if (HASH[c] == 1 && res < candies.size() / 2)
                res++;
        }
        return res;
    }
};