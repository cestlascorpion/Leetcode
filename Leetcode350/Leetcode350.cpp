//
// Created by hans on 18-4-24.
//

#include "Leetcode350.h"

void Leetcode350::test350() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> ans = intersect(nums1, nums2);
    for (auto item : ans)
        cout << item << " ";
    cout << endl;
}

vector<int> Leetcode350::intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans;
    if (nums1.empty() || nums2.empty())
        return ans;
    int L1 = nums1.size();
    int L2 = nums2.size();
    vector<int> &less = L1 < L2 ? nums1 : nums2;
    vector<int> &more = L1 < L2 ? nums2 : nums1;
    unordered_map<int, int> m;
    for (int i = 0; i < less.size(); ++i) {
        m[less[i]]++;
    }
    for (int i = 0; i < more.size(); ++i) {
        if (m.find(more[i]) != m.end()) {
            ans.push_back(more[i]);
            if (m[more[i]] == 1)
                m.erase(more[i]);
            else
                --m[more[i]];
        }
    }
    return ans;
}
