#include "0.config.h"

class Solution
{
  public:
    int addDigits(int num)
    {
        if (num / 10 == 0)
            return num;
        else
        {
            int s = 0;
            int n = num;
            while (n)
            {
                s += n % 10;
                n = n / 10;
            }
            return addDigits(s);
        }
    }
};
//Could you do it without any loop/recursion in O(1) runtime?
//https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
class Solution2
{
  public:
    int addDigits(int num)
    {
        if (num == 0)
            return 0;
        if (num % 9 == 0)
            return 9;
        return num % 9;
    }
};