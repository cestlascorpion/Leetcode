#include "0.config.h"

class Solution
{
  public:
    string reverseString(string s)
    {
        if (s.size() < 2)
            return s;
        int p1 = 0;
        int p2 = s.size() - 1;
        while (p1 < p2)
            swap(s[p1++], s[p2--]);
        return s;
    }
};