#include "0. config.h"

class Solution
{
  public:
    vector<string> findWords(vector<string> &words)
    {
        string rows[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> vs;
        for (int i = 0; i < words.size(); i++)
        {
            string s = words[i];
            int r = -1;
            int j = 0;
            for (j = 0; j < s.size(); j++)
            {
                if (r == -1)
                {
                    while (r < 2)
                    {
                        r++;
                        if (string::npos != rows[r].find(tolower(s[j])))
                        {
                            break;
                        }
                    }
                }
                else
                {
                    if (string::npos == rows[r].find(tolower(s[j])))
                    {
                        break;
                    }
                }
            }
            if (j == s.size())
            {
                vs.push_back(s);
            }
        }
        return vs;
    }
};