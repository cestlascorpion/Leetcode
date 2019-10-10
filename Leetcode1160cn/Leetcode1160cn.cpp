//
// Created by hans-01829 on 10/11/19.
//

#include "Leetcode1160cn.h"

int Leetcode1160cn::countCharacters(vector<string> &words, string chars) {
    int res = 0;

    sort(chars.begin(), chars.end());

    for (auto word : words) {
        sort(word.begin(), word.end());

        // -------------chars---------------
        //   idx
        // words
        int idx = 0;
        bool match = true;
        for (int i = 0; i < word.size(); ++i) {
            while (idx != chars.size() && chars[idx] != word[i]) {
                ++idx;
            }
            if (idx == chars.size()) {
                match = false;
                break;
            }
            ++idx; // one char is matched, the next
        }
        if (match) {
            res += word.size();
        }
    }

    return res;
}

int Leetcode1160cn::countCharacters2(vector<string> &words, string chars) {
    int res = 0;
    char dict[26] = {0};
    for (const auto &ch : chars) {
        ++dict[ch - 'a'];
    }

    for (const auto &str : words) {
        char word[26] = {0};
        for (const auto &ch : str) {
            ++word[ch - 'a'];
        }
        bool match = true;
        for (int i = 0; i < 26; ++i) {
            if (dict[i] < word[i]) {
                match = false;
                break;
            }
        }
        if (match) {
            res += str.size();
        }
    }
    return res;
}
