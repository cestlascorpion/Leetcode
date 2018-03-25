#include "0. config.h"

class Solution
{
  public:
    bool judgeSquareSum(int c)
    {
        int low = 0;
        int high = floor(sqrt(c));
        while (low <= high)
        {
            int sum = low * low + high * high;
            if (sum == c)
                return true;
            else if (sum > c)
                high--;
            else
                low++;
        }
        return false;
    }
};
class Solution2
{
  public:
    bool judgeSquareSum(int c)
    {
        set<int> s;
        int root = floor(sqrt(c));
        for (int i = 0; i <= root; i++)
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