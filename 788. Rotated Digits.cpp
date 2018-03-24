#include "0. config.h"

class Solution
{
  public:
    int rotatedDigits(int N)
    {
        int ans = 0;
        if (N < 1)
            return ans;
        for (int i = 1; i <= N; i++)
        {
            if (isGoodNum(i))
                ans++;
        }
        return ans;
    }
    bool isGoodNum(int i)
    {
        bool have2569 = false;
        while (i > 0)
        {
            int temp = i / 10;
            i = i % 10;
            if (i == 3 || i == 4 || i == 7)
                return false;
            if (i == 2 || i == 5 || i == 6 || i == 9)
                have2569 = true;
            i = temp;
        }
        if (have2569)
            return true;
        else
            return false;
    }
};