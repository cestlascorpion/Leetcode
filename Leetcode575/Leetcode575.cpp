//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode575.h"

int Leetcode575::distributeCandies(vector<int> &candies) {
    if (candies.size() % 2 != 0)
        return 0;
    unordered_map<int, int> map;
    int ans = 0;
    for (int c : candies) {
        map[c]++;
        if (map[c] == 1 && ans < candies.size() / 2)
            ++ans;
    }
    return ans;
}
