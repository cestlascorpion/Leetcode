#include "0.config.h"

class Solution
{
  public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (m <= 1)
            return true;

        int n = matrix[0].size();
        if (n <= 1)
            return true;

        for (int i = m - 2; i >= 0; i--)
        {
            int num = matrix[i][0];
            for (int j = 1; j <= n - 1 && j <= (m - 1) - i; j++)
            {
                if (matrix[i + j][j] != num)
                    return false;
            }
        }
        for (int i = n - 2; i >= 1; i--)
        {
            int num = matrix[0][i];
            for (int j = 1; j <= m - 1 && j <= (n - 1) - i; j++)
            {
                if (matrix[j][i + j] != num)
                    return false;
            }
        }
        return true;
    }
};