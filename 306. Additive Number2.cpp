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
      string s_third;
      long l_third = l_first + l_second;
      long2str(l_third, s_third);
      return num.substr(start, s_third.length()) == s_third && isValid(l_second, l_third, start + s_third.length(), num);
    }
  }
  bool isAdditiveNumber(string num)
  {
    if (num.length() < 3)
      return false;
    else
    {
      for (int i = 1; i < num.length() / 2.0; i++)
      {
        if (num[0] == '0' && i > 1)
          return false;
        else
        {
          long l_first;
          str2long(l_first, num.substr(0, i));
          for (int j = 1; num.length() - i - j >= i && num.length() - i - j >= j; j++)
          {
            if (num[i] == '0' && j > 1)
              break;
            else
            {
              long l_second;
              str2long(l_second, num.substr(i, j));
              if (isValid(l_first, l_second, i + j, num))
                return true;
            }
          }
        }
      }
      return false;
    }
  }
};