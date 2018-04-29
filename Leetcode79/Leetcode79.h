//
// Created by hans on 4/29/18.
//

#ifndef LEETCODE_LEETCODE79_H
#define LEETCODE_LEETCODE79_H

#include "../config.h"

class Leetcode79 {
public:
    bool exist(vector<vector<char>> &board, string word);

    void test79();

private:
    void helper(vector<vector<char>> &board, string word, int begin, int end, int i, int j, bool &ans);
};


#endif //LEETCODE_LEETCODE79_H
