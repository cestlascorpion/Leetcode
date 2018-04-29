//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode67.h"

string Leetcode67::addBinary(string a, string b) {
    string ans;
    if (a.empty() && b.empty())
        return ans;
    int la = a.size();
    int lb = b.size();
    int carry = 0;
    while (la != 0 || lb != 0) {
        int p = la ? a[--la] - '0' : 0;
        int q = lb ? b[--lb] - '0' : 0;
        int sum = p + q + carry;
        ans += to_string(sum % 2);
        carry = sum / 2;
    }
    if (carry == 1) {
        ans += "1";
    }
    return string(ans.rbegin(), ans.rend());
}

void Leetcode67::test67() {
    string a = "11";
    string b = "1";
    string ans = addBinary(a, b);
    cout << ans << endl;
}
