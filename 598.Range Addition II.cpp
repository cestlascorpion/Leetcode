#include "000.config.h"

class Solution
{
  public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        if (ops.size() == 0)
            return m * n;
        int a = INT_MAX, b = INT_MAX;
        for (int i = 0; i < ops.size(); ++i)
        {
            if (a > ops[i][0])
                a = ops[i][0];
            if (b > ops[i][1])
                b = ops[i][1];
        }
        return a * b;
    }
};