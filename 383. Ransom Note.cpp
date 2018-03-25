#include "0. config.h"

class Solution
{
  public:
    bool canConstruct(string ransomNote, string magazine)
    
    {
        map<char, int> MAP;
        for (int i = 0; i < ransomNote.length(); i++)
        {
            if (MAP.find(ransomNote[i]) == MAP.end())
                MAP[ransomNote[i]] = 1;
            else
                MAP[ransomNote[i]]++;
        }
        int index = 0;
        while (index < magazine.length())
        {
            if (MAP.size() == 0)
                return true;
            if (MAP.find(magazine[index]) != MAP.end())
            {
                if (MAP[magazine[index]] == 1)
                    MAP.erase(magazine[index]);
                else
                    MAP[magazine[index]]--;
            }
            index++;
        }
        return false;
    }
};
class Solution2 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(26, 0);
        for(auto c:magazine) ++hash[c-'a'];
        for(auto c:ransomNote) {
            if(--hash[c-'a'] < 0) return false;
        }
        return true;
    }
};