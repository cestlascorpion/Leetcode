//
// Created by Wang on 2019/11/12.
//

#ifndef LEETCODE_LEETCODE758CN_H
#define LEETCODE_LEETCODE758CN_H

#include <config.h>

class Leetcode758cn {
public:
    string boldWords(vector<string> &words, string S) {
        vector<int> flag(S.size(), 0);
        for (const auto &str:words) {
            for (int i = 0; i < S.size() - (str.size() - 1); ++i) {
                if (match(str, S, i)) {
                    mark(flag, i, str.size());
                }
            }
        }
        string res;
        bool begin = true;
        for (int i = 0; i < flag.size(); ++i) {
            if (flag[i] == 0) {
                if (!begin) {
                    res += "</b>";
                    begin = true;
                }
                res.push_back(S[i]);
            } else {
                if (begin) {
                    res += "<b>";
                    begin = false;
                }
                res.push_back(S[i]);
            }
        }
        if (!begin) {
            res += "</b>";
        }
        return res;
    }

    string boldWords2(vector<string> &words, string S) {
        string record = S;
        for (auto & word : words) {
            for (size_t pos = 0; (pos = S.find(word, pos)) != string::npos; pos++) {
                for (int j = pos; j < pos + word.size(); j++) {
                    record[j] = toupper(record[j]);
                }
            }
        }

        S.clear();
        bool isUpper = false;
        for (int i = 0; i < record.size(); i++) {
            if (isupper(record[i])) {
                if (!isUpper) {
                    S += "<b>";
                    isUpper = true;
                }
                S += tolower(record[i]);
            } else {
                if (isUpper) {
                    S += "</b>";
                    isUpper = false;
                }
                S += record[i];
            }
        }
        if (isUpper) {
            S += "</b>";
        }
        return S;
    }

private:
    bool match(const string &str, string S, int pos) {
        for (int i = 0; i < str.size(); ++i) {
            if (S[pos + i] != str[i]) {
                return false;
            }
        }
        return true;
    }

    void mark(vector<int> &vector, int pos, int len) {
        for (int i = 0; i < len; ++i) {
            ++vector[pos + i];
        }
    }
};


#endif //LEETCODE_LEETCODE758CN_H
