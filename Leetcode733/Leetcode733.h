//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE733_H
#define LEETCODE_LEETCODE733_H

#include <config.h>

class Leetcode733 {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor);

private:
    void floodFill(vector<vector<int>> &image, int oldColor, int x, int y, int newColor);
};


#endif //LEETCODE_LEETCODE733_H
