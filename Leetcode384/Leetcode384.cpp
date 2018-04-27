//
// Created by hans on 4/27/18.
//

#include "Leetcode384.h"

Leetcode384::Leetcode384(vector<int> nums) {
    for(auto item:nums)
        vec.push_back(item);
}

vector<int> Leetcode384::reset() {
    return vec;
}

vector<int> Leetcode384::shuffle() {
    vector<int> ans = vec;
    for (int i = 0; i < ans.size(); ++i) {
        int t = i + rand() % (ans.size() - i);
        swap(ans[i], ans[t]);
    }
    return ans;
}
