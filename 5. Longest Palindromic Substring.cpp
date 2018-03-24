#include "0.config.h"

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        string maxPalindrome;
        int length = s.length();
        int max = 1;
        if (length <= 1)
        {
            return s;
        }
        else
        {
            int i, j, k;
            for (i = 1; i < length - 1; i++)
            {
                int maxodd = 1;
                for (j = 1; i - j > -1 && i + j < length; j++)
                {
                    if (s.at(i - j) == s.at(i + j))
                    {
                        maxodd = maxodd + 2;
                        if (maxodd >= max)
                        {
                            max = maxodd;
                            maxPalindrome = s.substr(i - j, 2 * j + 1);
                        }
                    }
                    else
                        break;
                }
            }
            for (i = 1; i < length; i++)
            {
                int maxeven = 0;
                for (k = 1; i - k > -1 && i + k - 1 < length; k++)
                {
                    if (s.at(i - k) == s.at(i + k - 1))
                    {
                        maxeven = maxeven + 2;
                        if (maxeven >= max)
                        {
                            max = maxeven;
                            maxPalindrome = s.substr(i - k, 2 * k);
                        }
                    }
                    else
                        break;
                }
            }
        }
        return maxPalindrome.empty() ? s.substr(0, 1) : maxPalindrome;
    }
};