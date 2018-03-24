#include "0.config.h"

class Solution
{
  public:
    void str2long(long &long_temp, const string &string_temp)
    {
        stringstream stream(string_temp);
        stream >> long_temp;
    }
    void long2str(const long &long_temp, string &string_temp)
    {
        stringstream stream;
        stream << long_temp;
        string_temp = stream.str();
    }
    bool isValid(const long &l_first, const long &l_second, const int &start, string num)
    {
        if (start == num.length())
        {
            return true;
        }
        else
        {
            long third = l_first + l_second;
            long second = l_second;
            string sum;
            long2str(third, sum);
            return num.substr(start, sum.length()) == sum && isValid(second, third, start + sum.length(), num);
        }
    }
    bool isAdditiveNumber(string num)
    {
        if (num.length() < 3)
        {
            return false;
        }
        else
        {
            int i, j;
            for (i = 1; i <= num.length() / 2.0; i++)
            {
                if (num[0] == '0' && i > 1)
                {
                    return false; //结束
                }
                string s_first = num.substr(0, i);
                long l_first;
                str2long(l_first, s_first);
                for (j = 1; num.length() - j - i >= i && num.length() - j - i >= j; j++)
                {
                    if (num[i] == '0' && j > 1)
                    {
                        break; // 跳出内层循环，第 2 个数字的第 1 位是 0
                    }
                    string s_second = num.substr(i, j);
                    long l_second;
                    str2long(l_second, s_second);
                    if (isValid(l_first, l_second, i + j, num))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    }
};