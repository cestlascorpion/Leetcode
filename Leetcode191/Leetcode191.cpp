//
// Created by hans on 4/27/18.
//

#include "Leetcode191.h"

int Leetcode191::hammingWeight(uint32_t n) {
    int ans = 0;
    while (n != 0) {
        ++ans;
        n = n & (n - 1);
    }
    return ans;
}

void Leetcode191::test191() {
    vector<uint32_t> nums{3, 7, 10, 12345};
    for (auto item : nums) {
        cout << " number " << item << " have " << hammingWeight(item) << " (1) " << endl;
    }
    cout << endl;
}