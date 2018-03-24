#include "0.config.h"

class Solution
{
  public:
    int numJewelsInStones2(string J, string S)
    {
        if (J.length() < 1 || S.length() < 1)
            return 0;
        int ans = 0;
        for (int m = 0; m < J.length(); m++)
        {
            for (int n = 0; n < S.length(); n++)
            {
                if (J[m] == S[n])
                    ans++;
            }
        }
        return ans;
    }
};
class Solution2
{
  public:
    int numJewelsInStones(string J, string S)
    {
        if (J.length() < 1 || S.length() < 1)
            return 0;

        map<char, int> jmap;
        int ans = 0;

        for (int i = 0; i < J.length(); i++)
            jmap[J[i]] = i;

        for (int i = 0; i < S.length(); i++)
        {
            if (jmap.find(S[i]) != jmap.end())
                ans++;
        }
        return ans;
    }
};