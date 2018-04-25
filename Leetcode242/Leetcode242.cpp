//
// Created by hans on 4/25/18.
//

#include "Leetcode242.h"

bool Leetcode242::isAnagram(string s, string t) {
    if (s.length() != t.length())
        return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

void Leetcode242::test242() {
    string s = "cat";
    string t1 = "act";
    string t2 = "rat";
    cout << isAnagram(s, t1) << "==true?" << endl
         << isAnagram(s, t2) << "==false?" << endl;

}

bool Leetcode242::isAnagram2(string s, string t) {
    if (s.length() != t.length())
        return false;
    unordered_map<char, int> m;
    for (auto item:s)
        ++m[item];
    for (auto item:t) {
        if (m.find(item) == m.end())
            return false;
        else {
            if (m[item] < 1)
                return false;
            else
                --m[item];
        }
    }
    return true;
}
