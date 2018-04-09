#include "000.config.h"

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
class Solution2 //三人借书，三人还书
{
  public:
    vector<vector<char>> generation(vector<char> &in, vector<char> &out)
    {
        vector<vector<char>> ans;
        if (in.size() != out.size())
            return ans;
        int n = (in.size() + out.size()) / 2;
        vector<char> ch;
        ch.insert(ch.end(), in.begin(), in.end());
        ch.insert(ch.end(), out.begin(), out.end());
        helper(ans, ch, 0, 0, n, in, out, 0);
        return ans;
    }
    void helper(vector<vector<char>> &ans, vector<char> ch, int i, int o, int n, vector<char> &in, vector<char> &out, int loc)
    {
        if (i == o && loc == 2 * n)
        {
            ans.push_back(ch);
            return;
        }
        else
        {
            for (int index = loc; index < 2 * n; index++)
            {
                if (ch[index] >= 'A' && ch[index] <= 'Z')
                    i++;
                if (ch[index] >= 'a' && ch[index] <= 'z')
                    o++;
                if (i >= o)
                {
                    swap(ch[index], ch[loc]);
                    helper(ans, ch, i, o, n, in, out, loc + 1);
                    swap(ch[index], ch[loc]);
                }
                if (ch[index] >= 'A' && ch[index] <= 'Z')
                    i--;
                if (ch[index] >= 'a' && ch[index] <= 'z')
                    o--;
            }
        }
    }
};