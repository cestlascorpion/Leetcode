//
// Created by Wang on 2019/12/19.
//

#ifndef LEETCODE_LEETCODE937CN_H
#define LEETCODE_LEETCODE937CN_H

#include "config.h"

class Leetcode937cn {
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        if (logs.empty()) {
            return logs;
        }
        auto cmp = [](const string &first, const string &second) -> bool {
            string head_1, head_2;
            int index_1 = 0, index_2 = 0;
            while (index_1 < first.size() && first[index_1] != ' ') {
                head_1.push_back(first[index_1]);
                index_1 += 1;
            }
            while (index_1 < first.size() && first[index_1] == ' ') {
                index_1 += 1;
            }
            while (index_2 < second.size() && second[index_2] != ' ') {
                head_2.push_back(second[index_2]);
                index_2 += 1;
            }
            while (index_2 < second.size() && second[index_2] == ' ') {
                index_2 += 1;
            }
            string body_1 = first.substr(index_1);
            string body_2 = second.substr(index_2);
            bool body_1_is_num = body_1[0] >= '0' && body_1[0] <= '9';
            bool body_2_is_num = body_2[0] >= '0' && body_2[0] <= '9';
            if (body_1_is_num) {
                return false;
            } else if (body_2_is_num) {
                return true;
            } else {
                if (body_1 == body_2) {
                    return head_1 < head_2;
                } else {
                    return body_1 < body_2;
                }
            }
        };
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};

#endif // LEETCODE_LEETCODE937CN_H
