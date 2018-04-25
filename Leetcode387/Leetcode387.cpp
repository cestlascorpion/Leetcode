//
// Created by hans on 4/25/18.
//

#include "Leetcode387.h"

int Leetcode387::firstUniqChar(string s) {
    if (s.empty())
        return -1;
    unordered_map<char, int> hashmap;
    for (int i = 0; i < s.length(); i++) {
        if (hashmap.find(s[i]) == hashmap.end())
            hashmap[s[i]] = i;
        else
            hashmap[s[i]] = -1;
    }
    unordered_map<char, int>::iterator it = hashmap.begin();
    int ans = INT32_MAX;
    while (it != hashmap.end()) {
        if (it->second != -1)
            ans = min(ans, it->second);
        ++it;
    }
    return ans == INT32_MAX ? -1 : ans;
}

void Leetcode387::test387() {
    //string s = "itwqbtcdprfsuprkrjkausiterybzncbmdvkgljxuekizvaivszowqtmrttiihervpncztuoljftlxybpgwnjb";
    string s = "aa";
    cout << firstUniqChar(s) << endl;
}
