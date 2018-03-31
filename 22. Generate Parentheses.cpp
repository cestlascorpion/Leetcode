#include "0. config.h"

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        if (n < 1)
            return ans;
        string str;
        helper(ans, str, n, n);
        return ans;
    }
    void helper(vector<string> &ans, string str, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            ans.push_back(str);
            return;
        }
        else
        {
            if (left > 0)
                helper(ans, str + "(", left - 1, right);

            if (right > 0 && left < right)
                helper(ans, str + ")", left, right - 1);
        }
    }
};
class Solution2
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        if (n == 0)
            return ans;
        for (int c = 0; c < n; c++)
        {
            for (string left : generateParenthesis(c))
            {
                for (string right : generateParenthesis(n - 1 - c))
                    ans.push_back("(" + left + ")" + right);
            }
        }
    }
};