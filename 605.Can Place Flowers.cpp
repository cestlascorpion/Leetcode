#include "000.config.h"

class Solution
{
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int max = 0;
        int low = 0;
        int high = 0;
        while (low < flowerbed.size() && high < flowerbed.size())
        {
            while (low < flowerbed.size() && flowerbed[low] != 0)
                low++;
            high = low;
            while (high < flowerbed.size() && flowerbed[high] == 0)
                high++;
            if (low == 0 && high == flowerbed.size())
                max += maxFlowers(2 + high - low);
            else if (low == 0 || high == flowerbed.size())
                max += maxFlowers(1 + high - low);
            else
                max += maxFlowers(high - low);
            low = high;
        }
        return n <= max;
    }
    int maxFlowers(int n)
    {
        if ((n & 1) == 1)
            return n >> 1;
        else
            return (n >> 1) - 1;
    }
};
class Solution2
{
  public:
    bool canPlaceFlowers(vector<int> &bed, int n)
    {
        for (int i = 0; i < bed.size(); i++)
        {
            if (!bed[i] && (i == 0 || !bed[i - 1]) && (i == bed.size() - 1 || !bed[i + 1]))
            {
                bed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};