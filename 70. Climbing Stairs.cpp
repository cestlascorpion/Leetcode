#include "0. config.h"

class Solution
{
  public:
    int climbStairs(int n)
    {
        /*
        int stepone = 0;
        int steptwo = 1;
        int sum = 0;
        
        for(int i = 0;i < n; i ++)//到达第n阶的方法 = 到达第n-1阶的方法 + 到达第n-2阶的方法 f(1) = 1 f(2) = 2 
        {
            sum = stepone + steptwo;
            stepone = steptwo;
            steptwo = sum;
        }
        
        return sum;
        */
        if (n <= 2)
            return n;
        int onestep = 1;
        int twostep = 2;
        for (int i = 3; i <= n; i++)
        {
            int sum = onestep + twostep;
            onestep = twostep;
            twostep = sum;
        }
        return twostep;
    }
};