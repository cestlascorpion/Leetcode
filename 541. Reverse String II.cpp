#include "0. config.h"

class Solution
{
  public:
    string reverseStr(string s, int k)
    {
        int low = 0;
        int high = 0;
        int L = s.length() - 1;
        while (low <= L && high <= L)
        {
            high = low + k - 1;
            if (low <= L && high <= L)
                reverse(s, low, high);
            else if (low <= L && high > L)
                reverse(s, low, L);
            low = high + 1 + k;
            high = low;
        }
    }
    void reverse(string &s, int low, int high)
    {
        while (low < high)
            swap(s[low], s[high]);
    }
};