//L, R will be integers L <= R in the range [1, 10^6].
//
//R - L will be at most 10000.
#include <set>

class Solution
{
  public:
    int countPrimeSetBits(int L, int R)
    {
        int ans = 0;
        if (L > R)
            return ans;

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
    std::set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
};