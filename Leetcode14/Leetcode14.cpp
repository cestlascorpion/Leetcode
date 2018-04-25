//
// Created by hans on 4/25/18.
//

#include "Leetcode14.h"

string Leetcode14::longestCommonPrefix(vector<string> &strs) {
    string ans;
    if (strs.empty())
        return ans;
    if (strs.size() == 1)
        return strs[0];
    ans = strs[0];
    for (int i = 1; i < strs.size(); ++i) {
        ans = commonPrefix(ans, strs[i]);
    }
    return ans;
}

string Leetcode14::commonPrefix(string &a, string &b) {
    string ans;
    if (a.empty() || b.empty())
        return ans;
    for (int i = 0; i < min(a.length(), b.length()); ++i) {
        if (a[i] != b[i])
            return ans;
        else
            ans += a[i];
    }
    return ans;
}

void Leetcode14::test14() {
    string s1 = "flower", s2 = "flow", s3 = "flight";
    vector<string> strs = {s1, s2, s3};
    cout << longestCommonPrefix(strs) << endl;
}
