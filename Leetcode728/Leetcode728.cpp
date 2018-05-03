//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode728.h"

vector<int> Leetcode728::selfDividingNumbers(int left, int right) {
    vector<int> ans;
    if (left > right)
        return ans;
    for (int i = left; i <= right; i++) {
        if (isValid(i))
            ans.push_back(i);
    }
    return ans;
}

bool Leetcode728::isValid(int i) {
    set<int> s;
    int num = i;
    while (num) {
        s.insert(num % 10);
        num = num / 10;
    }
    if (s.count(0) != 0) {
        return false;
    }
    if (s.count(9) != 0) {
        s.erase(3);
    }
    if (s.count(8) != 0) {
        s.erase(4);
        s.erase(2);
    }
    if (s.count(6) != 0) {
        s.erase(3);
        s.erase(2);
    }
    if (s.count(4) != 0) {
        s.erase(2);
    }
    if (s.count(1) != 0) {
        s.erase(1);
    }
    if (s.empty())
        return true;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        if (i % *it != 0)
            return false;
    }
    return true;
}
