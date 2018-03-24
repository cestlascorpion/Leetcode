#include "0. config.h"

class Solution
{
  public:
    char findTheDifference(string s, string t)
    {
        char ans;
        unordered_map<char, int> hMap;
        for (int i = 0; i < s.length(); i++)
        {
            if (hMap.find(s[i]) == hMap.end())
                hMap[s[i]] = 1;
            else
                hMap[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (hMap.find(t[i]) == hMap.end())
                return t[i];
            else
            {
                if (hMap[t[i]] == 0)
                    return t[i];
                else
                    hMap[t[i]]--;
            }
        }
        return ' ';
    }
};
class Solution2
{
  public:
    char findTheDifference(string s, string t)
    {
        char res = 0;

        for (char c : s)
            res ^= c;
        for (char c : t)
            res ^= c;

        return res;
    }
};