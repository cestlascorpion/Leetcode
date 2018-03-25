#include "0. config.h"

class Solution
{
  public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        if (houses.size() < 1)
            return 0;
        if (heaters.size() < 1)
            return -1;
        int ans = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < houses.size(); i++)
        {
            int radius = findNearHeater(houses[i], 0, heaters.size() - 1, heaters);
            ans = ans < radius ? radius : ans;
        }
        return ans;
    }
    int findNearHeater(int loc, int low, int high, vector<int> &h)
    {
        while (low <= high)
        {
            if (h[low] >= loc)
                return h[low] - loc;
            if (h[high] <= loc)
                return loc - h[high];
            int mid = (low + high) >> 1;
            return min(findNearHeater(loc, low, mid, h), findNearHeater(loc, mid + 1, high, h));
        }
    }
};