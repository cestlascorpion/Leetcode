//L, R will be integers L <= R in the range [1, 10^6].
//
//R - L will be at most 10000.
#include "0.config.h"

class Solution
{
  public:
    int countPrimeSetBits(int L, int R)
    {
        int ans = 0;
        if (L > R)
            return ans;
        primes.insert(2);
        primes.insert(3);
        primes.insert(5);
        primes.insert(7);
        primes.insert(11);
        primes.insert(13);
        primes.insert(17);
        primes.insert(19);
        for (int i = L; i <= R; i++)
        {
            int bits = getBits(i);
            if (isPrime(bits))
                ans++;
        }
        return ans;
    }
    int getBits(int num)
    {
        int res = 0;
        while (num)
        {
            if ((num & 1) == 1)
                res++;
            num = num >> 1;
        }
        return res;
    }
    bool isPrime(int num)
    {
        if (primes.count(num) == 0)
            return false;
        else
            return true;
    }

  private:
    set<int> primes;
};