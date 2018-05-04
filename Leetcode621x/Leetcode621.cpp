//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode621.h"

int Leetcode621::leastInterval(vector<char> &tasks, int n) {
    vector<int> helper(26, 0);
    for (auto ch : tasks)
        helper[ch - 'A']++;
    sort(helper.begin(), helper.end());
    int i = 25;
    while (i >= 0 && helper[25] == helper[i])
        i--;
    return max((helper[25] - 1) * (n + 1) + (25 - i), (int) tasks.size());
}
