#include "0. config.h"

class Solution
{
  public:
    bool isUgly(int num)
    {
        if (num == 0)
            return false;
        if (num == 1)
            return true;
        while (num != 1)
        {
            if (num % 2 == 0)
            {
                num = num / 2;
                continue;
            }
            if (num % 3 == 0)
            {
                num = num / 3;
                continue;
            }
            if (num % 5 == 0)
            {
                num = num / 5;
                continue;
            }
            return false;
        }
        return true;
    }
};
class Solution
{
  public:
    int ugly(int n)
    {
        if (n <= 0)
            return 0;
        vector<int> uglynumber(n, 0);
        uglynumber[0] = 1;
        int nextUglyIndex = 1;

        int p2, p3, p5 = 0;

        while (nextUglyIndex < n)
        {
            int minnum = min(uglynumber[p2] * 2, uglynumber[p3] * 3, uglynumber[p5] * 5);
            uglynumber[nextUglyIndex] = minnum;
            while (uglynumber[p2] * 2 <= uglynumber[nextUglyIndex])
                p2++;
            while (uglynumber[p3] * 3 <= uglynumber[nextUglyIndex])
                p3++;
            while (uglynumber[p5] * 5 <= uglynumber[nextUglyIndex])
                p5++;
            nextUglyIndex++;
        }
        int ans = uglynumber[nextUglyIndex - 1];
        return ans;
    }
};