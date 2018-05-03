//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode605.h"

bool Leetcode605::canPlaceFlowers(vector<int> &bed, int n) {
    for (int i = 0; i < bed.size(); ++i) {
        if (!bed[i] && (i == 0 || !bed[i - 1]) && (i == bed.size() - 1 || !bed[i + 1])) {
            bed[i] = 1;
            n--;
        }
    }
    return n <= 0;
}

bool Leetcode605::canPlaceFlowers2(vector<int> &flowerbed, int n) {
    int max = 0;
    int low = 0;
    int high = 0;
    while (low < flowerbed.size() && high < flowerbed.size())
    {
        while (low < flowerbed.size() && flowerbed[low] != 0)
            ++low;
        high = low;
        while (high < flowerbed.size() && flowerbed[high] == 0)
            ++high;
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
