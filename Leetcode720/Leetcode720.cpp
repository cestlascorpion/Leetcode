//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode720.h"

string Leetcode720::longestWord(vector<string> &words) {
    string ans;
    int maxLen = 0;
    unordered_set<string> s(words.begin(), words.end());
    queue<string> q;
    for (string word : words) {
        if (word.size() == 1)
            q.push(word);
    }
    while (!q.empty()) {
        string t = q.front();
        q.pop();
        if (t.length() > maxLen) {
            maxLen = t.length();
            ans = t;
        } else if (t.size() == maxLen) {
            ans = min(ans, t);
        }
        for (char c = 'a'; c <= 'z'; c++) {
            t.push_back(c);
            if (s.count(t))
                q.push(t);
            t.pop_back();
        }
    }
    return ans;
}

string Leetcode720::longestWord2(vector<string> &words) {
    sort(words.begin(), words.end());
    unordered_set<string> Set;
    string ans;
    for (string w : words) {
        if (w.length() == 1 || Set.count(w.substr(0, w.length() - 1))) {
            ans = w.length() > ans.length() ? w : ans;
            Set.insert(w);
        }
    }
    return ans;
}


