//
// Created by hans on 4/25/18.
//

#include "Leetcode38.h"

string Leetcode38::countAndSay(int n) {
    string s = "1";
    string ans;
    if (n < 1)
        return ans;

    while (n > 1) {
        for (int i = 0; i < s.size(); ) {
            int cnt = 0;
            int j = i;
            while (s[i] == s[j] && j < s.size()) {
                j++;
                cnt++;
            }
            ans += to_string(cnt);
            ans += s[i];
            i = j;
            //cout<<i<<endl;
        }
        s=ans;
        ans.clear();
        --n;
    }
    return s;
}

void Leetcode38::test38() {
    string ans = countAndSay(5);
    cout << ans << endl;
}
