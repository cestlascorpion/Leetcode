//
// Created by hans on 18-4-23.
//

#include "Leetcode26.h"

int Leetcode26::removeDuplicates(vector<int> &nums) {
    if (nums.empty())
        return 0;
    int ans = 0;
    int key = nums[0] - 1;
    for (int i = 0; ans < nums.size() && i < nums.size(); ++i) {
        if (nums[i] > key) {
            nums[ans] = nums[i];
            ans++;
            key=nums[i];
        }
    }
    nums.resize(ans);
    return ans;
}

void Leetcode26::test26() {
    vector<int> v1 = {1};
    vector<int> v2 = {1, 1, 2};
    vector<int> v3 = {1, 1, 1, 2, 2, 3, 3, 3};
    vector<int> v4 = {0, 1, 1, 2};
    cout << removeDuplicates(v1) << endl
         << removeDuplicates(v2) << endl
         << removeDuplicates(v3) << endl
         << removeDuplicates(v4) << endl;
    cout << "test over." << endl;
}