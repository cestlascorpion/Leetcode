//
// Created by hans on 18-4-23.
//

#include "Leetcode189.h"

void Leetcode189::test189() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};

    rotate(v, 8);
    for (auto item:v)
        cout << item << " ";
    cout << endl;
}

void Leetcode189::rotate(vector<int> &nums, int k) {
    if (nums.empty())
        return;
    int n = nums.size();
    k = k % n;

    int start = 0;
    int end = n - 1 - k;

    while (start < end)
        swap(nums[start++], nums[end--]);
    start = n - k;
    end = n - 1;

    while (start < end)
        swap(nums[start++], nums[end--]);

    reverse(nums.begin(), nums.end());
}
