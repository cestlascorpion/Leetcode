#include "000.config.h"

class Solution
{
  public:
    int firstUniqChar(string s)
    {
        if (s.length() <= 0)
            return -1;
        unordered_map<char, int> hashmap;
        for (int i = 0; i < s.length(); i++)
        {
            if (hashmap.find(s[i]) == hashmap.end())
                hashmap[s[i]] = i;
            else
                hashmap[s[i]] = -1;
        }
        unordered_map<char, int>::iterator it = hashmap.begin();
        int ans = -1;
        while (it != hashmap.end())
        {
            if (it->second != -1)
                ans = ans > it->second ? it->second : ans;
        }
        return ans;
    }
};
