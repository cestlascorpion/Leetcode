//
// Created by hans on 4/27/18.
//

#include "Leetcode20.h"

bool Leetcode20::isValid(string s) {
    int len = s.size();

    stack<char> helper;
    for (int i = 0; i < len; i++) {
        helper.push(s[i]);
        char temp = helper.top();
        if (temp == '(' || temp == '{' || temp == '[')
            continue;

        if (temp == ')' || temp == '}' || temp == ']') {
            helper.pop();
            if (helper.empty())
                return false;

            if ((temp == ')' && helper.top() == '(') || (temp == '}' && helper.top() == '{') ||
                (temp == ']' && helper.top() == '[')) {
                helper.pop();
                continue;
            } else
                return false;

        }
    }
    if (helper.empty())
        return true;
    else
        return false;
}

void Leetcode20::test20() {
    vector<string> str{"((", "([)]", "[({})]"};
    for (auto item:str) {
        cout << item << " -> " << isValid(item) << endl;
    }
    cout << endl;
}
