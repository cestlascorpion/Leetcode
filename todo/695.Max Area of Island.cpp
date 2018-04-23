#include "000.config.h"

class Solution
{
  public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m < 0)
            return 0;
        int n = grid[0].size();
        if (n < 0)
            return 0;
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    ans = max(ans, calArea(m, n, i, j, grid));
            }
        }
        return ans;
    }
    int calArea(int m, int n, int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || grid[i][j] != 1)
            return 0;

        if (grid[i][j] == 1)
        {
            grid[i][j] = 0;
            return 1 + calArea(m, n, i - 1, j, grid) + calArea(m, n, i + 1, j, grid) + calArea(m, n, i, j - 1, grid) + calArea(m, n, i, j + 1, grid);
        }
        return 0;
    }
};