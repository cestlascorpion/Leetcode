#include "000.config.h"

class Solution
{
  public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        int ans = 0;
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < houses.size(); i++)
        {
            int index = binarySearch(heaters, houses[i]);
            int dist1 = index - 1 >= 0 ? houses[i] - heaters[index - 1] : INT_MAX;
            int dist2 = index < heaters.size() ? heaters[index] - houses[i] : INT_MAX;
            ans = max(ans, min(dist1, dist2));
        }
        return ans;
    }
    int binarySearch(vector<int> &v, int target)
    {
        int lo = 0, hi = v.size() - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] == target)
                return mid;
            else if (v[mid] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return lo;
    }
};