#include "000.config.h"

class Solution
{
  public:
    int hammingDistance(int x, int y)
    {
        int temp = x ^ y;
        int result = 0;
        if (temp == 0)
        {
            return result;
        }
        while (temp != 0)
        {
            if ((temp & 1) == 1)
                result++;
            temp = temp >> 1;
        }
        return result;
    }
};