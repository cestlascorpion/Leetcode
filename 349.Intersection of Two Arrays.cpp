#include "000.config.h"

class Solution
{
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_set<int> s1;
        s1.insert(nums1.begin(), nums1.end());
        unordered_set<int> s2;
        s2.insert(nums2.begin(), nums2.end());
        for (unordered_set<int>::iterator it = s1.begin(); it != s1.end(); it++)
        {
            if (s2.find(*it) != s2.end())
                ans.push_back(*it);
        }
        return ans;
    }
};