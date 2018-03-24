#include "0. config.h"

class Solution
{
  public:
    int reverse(int x)
    {
        if (x == 0)
            return 0;
        else
        {
            long long temp = 0;
            while (x)
            {
                temp = temp * 10 + x % 10;
                x /= 10;
            }
            return (temp < INT_MIN || temp > INT_MAX) ? 0 : temp;
        }
    }
};