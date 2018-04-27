//
// Created by cestl on 2018/4/28 0028.
//

#include "Leetcode3.h"

int Leetcode3::lengthOfLongestSubstring(string s) {
    if (s.empty())
        return 0;
    int ans = 0;
    map<char, int> m;//char->index
    int tail = 0;
    for (int head = 0; head < s.length(); ++head) {
        if (m.find(s[head]) == m.end()) {
            m[s[head]] = head;
        } else {
            while (tail <= m[s[head]]) {
                m.erase(s[tail]);
                ++tail;
            }
            m[s[head]] = head;
        }
        //cout << " head " << head << " tail " << tail << endl;
        ans = max(ans, head - tail + 1);
    }
    return ans;
}

void Leetcode3::test3() {
    vector<string> str = {"abcabcbb", "bbbb","pwwkew"};
    for (auto s:str) {
        cout << lengthOfLongestSubstring(s) << endl;
    }
}

int Leetcode3::lengthOfLongestSubstring2(string s)     {
    if (s.empty())
        return 0;

    map<char, int> record;
    int maxlen = 0;
    int repeatIndex = -1;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (record.find(s[i]) != record.end() && record[s[i]] > repeatIndex)
        {
            repeatIndex = record[s[i]];
        }
        if (maxlen < i - repeatIndex)
        {
            maxlen = i - repeatIndex;
        }
        record[s[i]] = i;
    }
    return maxlen;
}
