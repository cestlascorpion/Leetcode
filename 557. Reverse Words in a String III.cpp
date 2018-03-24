#include "0.config.h"

class Solution
{
  public:
    string reverseWords(string s)
    {
        string str(""); //空字符串
        int count = 0;
        int num = s.size();
        for (int i = 0; i < num; i++) //遍历整个S
        {
            if (s[i] == ' ') //分割点
            {
                string temp(i - count, ' ');
                for (int j = 0; j < i + 1 - count; j++)
                {
                    temp[j] = s[i - j - 1];
                }
                str = str + temp + ' ';
                count = i + 1;
            }
            else
            {
                if (i == num - 1)
                {
                    i = num;
                    string temp(i - count, ' ');
                    for (int j = 0; j < i + 1 - count; j++)
                    {
                        temp[j] = s[i - j - 1];
                    }
                    str = str + temp;
                }
            }
        }
        return str;
    }
};