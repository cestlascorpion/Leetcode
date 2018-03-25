#include "0. config.h"

class Solution
{
  public:
    bool judgeSquareSum(int c)
    {
        set<int> s;
        for (int i = 0; i * i <= c; i++)
            s.insert(i * i);
        for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        {
            if (s.find(c - *it) != s.end())
                return true;
            if ((*it) * 2 > c)
                break;
        }
        return false;
    }
};