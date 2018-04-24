//
// Created by hans on 18-4-24.
//

#include "Leetcode136.h"

int Leetcode136::singleNumber(vector<int> &nums) {
    int ans = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        ans ^= nums[i];
    }
    return ans;
}

void Leetcode136::test136() {
    vector<int> v1 = {2, 2, 1};
    vector<int> v2 = {1, 2, 1, 2};
    cout<<singleNumber(v1)<<" "<<singleNumber(v2)<<endl;
}
