#include "000.config.h"

class Solution
{
  public:
    string convertToTitle(int n)
    {
        string res;
        stack<char> stk;
        while (n)
        {
            int d = (n - 1) % 26;
            stk.push(d + 'A');
            n = (n - 1) / 26;
        }
        while (!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};