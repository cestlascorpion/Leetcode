//
// Created by hans on 18-4-24.
//

#include "Leetcode66.h"

vector<int> Leetcode66::plusOne(vector<int> &digits) {
    int end = digits.size() - 1;
    if (digits[end] < 9) {
        digits[end]++;
        return digits;
    }
    int carry = 1;
    int res = 0;
    vector<int> ans;
    for (int i = digits.size() - 1; i >= 0; --i) {
        res = (digits[i] + carry) % 10;
        carry = (digits[i] + carry) / 10;
        ans.push_back(res);
    }
    if (carry == 1)
        ans.push_back(1);
    reverse(ans.begin(), ans.end());
    return ans;
}

void Leetcode66::test66() {
    vector<int> nums = {9, 9};
    for (auto item:nums)
        cout << item << " ";
    cout << endl;
    vector<int> ans = plusOne(nums);
    for (auto item:ans)
        cout << item << " ";
    cout << endl;
}
