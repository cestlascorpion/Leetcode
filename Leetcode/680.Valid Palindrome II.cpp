#include "000.config.h"

class Solution
{
  public:
    bool validPalindrome(string s)
    {
        int lo = 0;
        int hi = s.length() - 1;
        while (lo < hi)
        {
            if (s[lo] == s[hi])
            {
                lo++;
                hi--;
            }
            else
                return isvalid(s, lo + 1, hi) || isvalid(s, lo, hi - 1);
        }
        return true;
    }
    bool isvalid(string &s, int lo, int hi)
    {
        while (lo < hi)
        {
            if (s[lo] != s[hi])
                return false;
            lo++;
            hi--;
        }
        return true;
    }
};