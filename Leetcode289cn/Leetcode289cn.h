//
// Created by Wang on 2019/11/22.
//

#ifndef LEETCODE_LEETCODE289CN_H
#define LEETCODE_LEETCODE289CN_H

#include <config.h>

class Leetcode289cn {
public:
    void gameOfLife(vector<vector<int>> &board);

private:
    void mark(vector<vector<int>> &board, int i, int j, int row, int col);

    void change(vector<vector<int>> &board, int i, int j);

    bool valid(int i,int j, int row, int col);
};


#endif //LEETCODE_LEETCODE289CN_H
