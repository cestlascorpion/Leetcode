//
// Created by Wang on 2019/10/20.
//

#include "leetcode884cn.h"

vector<string> leetcode884cn::uncommonFromSentences(string A, string B) {
    auto vec_a = regex_split(A, " ");
    unordered_map<string, int> map_a;
    for (const auto &s : vec_a) {
        ++map_a[s];
    }

    auto vec_b = regex_split(B, " ");
    unordered_map<string, int> map_b;
    for (const auto &s : vec_b) {
        ++map_b[s];
    }

    vector<string> res;
    for (const auto &p : map_a) {
        if (p.second != 1) {
            continue;
        }
        if (map_b.find(p.first) != map_b.end()) {
            continue;
        }
        res.push_back(p.first);
    }
    for (const auto &p : map_b) {
        if (p.second != 1) {
            continue;
        }
        if (map_a.find(p.first) != map_a.end()) {
            continue;
        }
        res.push_back(p.first);
    }

    return res;
}

vector<string> leetcode884cn::regex_split(const string &str, const string &ch) {
    regex re{ch};
    return vector<string>{sregex_token_iterator(str.begin(), str.end(), re, -1), sregex_token_iterator()};
}
vector<string> leetcode884cn::uncommonFromSentences2(string A, string B) {
    auto vec = regex_split(A + " " + B, " ");
    unordered_map<string, int> map;
    for (const auto &s : vec) {
        ++map[s];
    }
    vector<string> res;
    for (const auto &p : map) {
        if (p.second == 1) {
            res.push_back(p.first);
        }
    }
    return res;
}
vector<string> leetcode884cn::uncommonFromSentences3(string A, string B) {
    string str = A + " " + B;
    int idx = 0;
    unordered_map<string, int> map;
    while (idx < str.size()) {
        int p = idx + 1;
        while (p < str.size() && str[p] != ' ') {
            ++p;
        }
        string s = str.substr(idx, p - idx);
        ++map[s];
        idx = p + 1;
    }
    vector<string> res;
    for (const auto &p : map) {
        if (p.second == 1) {
            res.push_back(p.first);
        }
    }
    return res;
}
