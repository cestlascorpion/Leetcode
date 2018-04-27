//
// Created by cestl on 2018/4/27 0027.
//

#include "Leetcode49.h"

vector<vector<string>> Leetcode49::groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    map<string, vector<string> *> index;//string->index of ans
    for (auto str:strs) {
        string s = str;
        sort(s.begin(), s.end());
        if (index.find(s) == index.end()) {
            vector<string> *p = new vector<string>;//make cause memory leak
            p->push_back(str);
            index.insert(make_pair(s, p));
        } else {
            index[s]->push_back(str);
        }
    }
    for (auto item:index) {
        ans.push_back((*item.second));
    }
    return ans;
}

void Leetcode49::test49() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ans = groupAnagrams(strs);
    for (auto item:ans) {
        for (auto jtem:item) {
            for (auto ktem:jtem) {
                cout << ktem << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;

}
