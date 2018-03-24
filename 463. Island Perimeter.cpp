#include "0. config.h"

class Solution
{
  public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m < 1)
            return 0;
        int n = grid[0].size();
        if (n < 1)
            return 0;
        int ans = 0;
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                {
                    if (row == 0)
                        ans++;
                    if (row == m - 1)
                        ans++;
                    if (row > 0 && grid[row - 1][col] == 0)
                        ans++;
                    if (row < m - 1 && grid[row + 1][col] == 0)
                        ans++;

                    if (col == 0)
                        ans++;
                    if (col == n - 1)
                        ans++;
                    if (col > 0 && grid[row][col - 1] == 0)
                        ans++;
                    if (col < n - 1 && grid[row][col + 1] == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};