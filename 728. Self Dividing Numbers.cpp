#include "0. config.h"

class Solution
{
  public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        if (left > right)
            return ans;
        for (int i = left; i <= right; i++)
        {
            if (isValid(i))
                ans.push_back(i);
        }
        return ans;
    }

  private:
    bool isValid(int i)
    {
        set<int> s;
        int num = i;
        while (num)
        {
            s.insert(num % 10);
            num = num / 10;
        }
        if (s.count(0) != 0)
        {
            return false;
        }
        if (s.count(9) != 0)
        {
            s.erase(3);
        }
        if (s.count(8) != 0)
        {
            s.erase(4);
            s.erase(2);
        }
        if (s.count(6) != 0)
        {
            s.erase(3);
            s.erase(2);
        }
        if (s.count(4) != 0)
        {
            s.erase(2);
        }
        if (s.count(1) != 0)
        {
            s.erase(1);
        }
        if (s.empty())
            return true;
        for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        {
            if (i % *it != 0)
                return false;
        }
        return true;
    }
};
class Solution2
{
  public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> rslt;
        for (int n = left; n <= right; n++)
        {
            if (isSelfDividing(n))
                rslt.push_back(n);
        }
        return rslt;
    }
    bool isSelfDividing(int n)
    {
        int x = n;
        while (x)
        {
            int d = x % 10;
            if (d == 0)
                return false;
            if (n % d != 0)
                return false;
            x = x / 10;
        }
        return true;
    }
};