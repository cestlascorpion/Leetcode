#include "000.config.h"

class Solution
{
  public:
    int calPoints(vector<string> &ops)
    {
        int len = ops.size();
        vector<int> s;
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
            if (ops[i] == "C")
                s.pop_back();
            else if (ops[i] == "D")
                s.push_back(s[s.size() - 1] * 2);
            else if (ops[i] == "+")
                s.push_back(s[s.size() - 1] + s[s.size() - 2]);
            else
                s.push_back(stoi(ops[i]));
        }
        return accumulate(s.begin(), s.end(), 0);
    }
};