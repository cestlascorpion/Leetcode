#include "000.config.h"

class Solution
{
  public:
    bool hasAlternatingBits(int n)
    {
        int flag = n & 1;
        do
        {
            n = n >> 1;
            if ((n & 1) == flag)
                return false;
            flag = n & 1;
        } while (n);
        return true;
    }
};