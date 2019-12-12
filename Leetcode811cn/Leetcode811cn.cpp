//
// Created by Wang on 2019/12/12.
//

#include "Leetcode811cn.h"

vector<string> Leetcode811cn::subdomainVisits(vector<string> &cpdomains) {
    map<string, int> counter;
    for (const auto &str : cpdomains) {
        helper(str, counter);
    }
    vector<string> res(counter.size());
    int i = 0;
    for (const auto &count : counter) {
        res[i] = (to_string(count.second) + " " + count.first);
        ++i;
    }
    return res;
}

void Leetcode811cn::helper(const string &str, map<string, int> &counter) {
    if (str.empty())
        return;
    int space = 0;
    while (space < str.size() && str[space] != ' ')
        ++space;
    if (space == str.size())
        return;

    int num = stoi(str.substr(0, space));
    string domain = str.substr(space + 1);
    while (!domain.empty()) {
        counter[domain] += num;
        auto pos = domain.find('.');
        if (pos == string::npos)
            break;
        domain = domain.substr(pos + 1);
    }
}