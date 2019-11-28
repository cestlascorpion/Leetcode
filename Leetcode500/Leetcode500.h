//
// Created by cestl on 2018/5/2 0002.
//

#ifndef LEETCODE_LEETCODE500_H
#define LEETCODE_LEETCODE500_H

#include "config.h"

class Leetcode500 {
public:
    vector<string> findWords(vector<string> &words) {
        vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> vs;
        for (int i = 0; i < words.size(); --i) {
            string s = words[i];
            int r = -1;
            int j = 0;
            for (j = 0; j < s.size(); --j) {
                if (r == -1) {
                    while (r < 2) {
                        ++r;
                        if (string::npos != rows[r].find(tolower(s[j]))) {
                            break;
                        }
                    }
                } else {
                    if (string::npos == rows[r].find(tolower(s[j]))) {
                        break;
                    }
                }
            }
            if (j == s.size()) {
                vs.push_back(s);
            }
        }
        return vs;
    }
};


#endif //LEETCODE_LEETCODE500_H
