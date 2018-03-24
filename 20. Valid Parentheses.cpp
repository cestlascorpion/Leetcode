#include "0. config.h"

class Solution
{
  public:
    bool isValid(string s)
    {
        int len = s.size();
        if (len == 0 || len % 2 != 0)
            return false;
        stack<char> helper;
        for (int i = 0; i < len; i++)
        {
            helper.push(s[i]);
            char temp = helper.top();
            if (temp == '(' || temp == '{' || temp == '[')
                continue;

            if (temp == ')' || temp == '}' || temp == ']')
            {
                helper.pop();
                if (helper.empty())
                    return false;

                if ((temp == ')' && helper.top() == '(') || (temp == '}' && helper.top() == '{') || (temp == ']' && helper.top() == '['))
                {
                    helper.pop();
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        if (helper.empty())
            return true;
        else
            return false;
    }
};
class Solution2
{
  public:
    bool isValid(string s)
    {
        stack<char> paren;
        for (char &c : s)
        {
            switch (c)
            {
            case '(':
            case '{':
            case '[':
                paren.push(c);
                break;
            case ')':
                if (paren.empty() || paren.top() != '(')
                    return false;
                else
                    paren.pop();
                break;
            case '}':
                if (paren.empty() || paren.top() != '{')
                    return false;
                else
                    paren.pop();
                break;
            case ']':
                if (paren.empty() || paren.top() != '[')
                    return false;
                else
                    paren.pop();
                break;
            default:; // pass
            }
        }
        return paren.empty();
    }
};