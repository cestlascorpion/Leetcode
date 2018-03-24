#include "0. config.h"

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;

        map<char, int> record;
        int maxlen = 0;
        int repeatIndex = -1;
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            if (record.find(s[i]) != record.end() && record[s[i]] > repeatIndex)
            {
                repeatIndex = record[s[i]];
            }
            if (maxlen < i - repeatIndex)
            {
                maxlen = i - repeatIndex;
            }
            record[s[i]] = i;
        }
        return maxlen;
    }
};