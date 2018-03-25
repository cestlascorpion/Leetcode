#include "0. config.h"

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() <= 0)
            return "";
        if (strs.size() == 1)
            return strs[0];
        string ans = strs[0];
        for (int i = 1; i <= strs.size() - 1; i++)
        {
            ans = commonPrefix(ans, strs[i]);
        }
        return ans;
    }
    string commonPrefix(string &a, string &b)
    {
        if (a.length() <= 0 || b.length() <= 0)
            return "";
        string ans;
        for (int i = 0; i < min(a.length(), b.length()); i++)
        {
            if (a[i] != b[i])
                return ans;
            else
                ans += a[i];
        }
        return ans;
    }
};