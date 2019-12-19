//
// Created by Wang on 2019/12/19.
//

#include "Leetcode929cn.h"

int Leetcode929cn::numUniqueEmails(vector<string> &emails) {
    set<string> unique;
    for (const auto &str : emails) {
        auto res = handle(str);
        if (!res.empty()) {
            // cout << res << endl;
            unique.insert(move(res));
        }
    }
    return unique.size();
}

string Leetcode929cn::handle(const string &str) {
    int end = str.find('@');
    if (end == string::npos) {
        return string();
    }
    string res;
    bool flag = false;
    for (int i = 0; !flag && i < end; ++i) {
        switch (str[i]) {
        case '+':
            flag = true;
            break;
        case '.':
            break;
        default:
            res.push_back(str[i]);
        }
    }
    res += str.substr(end);
    return res;
}
