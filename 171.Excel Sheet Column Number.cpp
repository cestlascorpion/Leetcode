#include "000.config.h"

class Solution
{
  public:
    int titleToNumber(string s)
    {
        if (s.length() <= 0)
            return 0;
        int ans = 0;
        int base = 1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            ans = (s[i] - 'A' + 1) * base + ans;
            base = base * 26;
        }
        return ans;
    }
};