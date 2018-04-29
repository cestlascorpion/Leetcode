//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode349.h"

vector<int> Leetcode349::intersection(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans;
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());
    //suppose s1.size()>s2.size()
    for (auto it = s1.begin(); it != s1.end(); ++it) {
        if (s2.find(*it) != s2.end())
            ans.push_back(*it);
    }
    return ans;
}
