#include "000.config.h"

class Solution2
{
  public:
    string longestWord(vector<string> &words)
    {
        string ans;
        int maxLen = 0;
        unordered_set<string> s(words.begin(), words.end());
        queue<string> q;
        for (string word : words)
        {
            if (word.size() == 1)
                q.push(word);
        }
        while (!q.empty())
        {
            string t = q.front();
            q.pop();
            if (t.length() > maxLen)
            {
                maxLen = t.length();
                ans = t;
            }
            else if (t.size() == maxLen)
            {
                ans = min(ans, t);
            }
            for (char c = 'a'; c <= 'z'; c++)
            {
                t.push_back(c);
                if (s.count(t))
                    q.push(t);
                t.pop_back();
            }
        }
        return ans;
    }
};
class Solution
{
  public:
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end());
        unordered_set<string> Set;
        string res = "";
        for (string w : words)
        {
            if (w.length() == 1 || Set.count(w.substr(0, w.length() - 1)))
            {
                res = w.length() > res.length() ? w : res;
                Set.insert(w);
            }
        }
        return res;
    }
};