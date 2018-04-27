//
// Created by hans on 4/27/18.
//

#include "Leetcode88.h"

void Leetcode88::merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    if (n == 0)
        return;
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            --p;
            --p1;
        } else {
            nums1[p] = nums2[p2];
            --p;
            --p2;
        }
    }
    while (p1 >= 0) {
        nums1[p--] = nums1[p1--];
    }
    while (p2 >= 0) {
        nums1[p--] = nums2[p2--];
    }
}

void Leetcode88::test88() {
    vector<int> nums1 = {1, 2, 5, 11, 15, 0, 0, 0};
    vector<int> nums2 = {4, 8, 12};
    merge(nums1, 5, nums2, 3);
    for (auto item : nums1)
        cout << item << " ";
    cout << endl;
}
