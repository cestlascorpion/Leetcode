//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode240.h"

bool Leetcode240::searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
        return false;

    //右上角
    int i = 0;
    int j = matrix[0].size() - 1;

    int row = matrix.size();
    int col = matrix[0].size();

    while (i < row && j >= 0) {
        if (matrix[i][j] == target)
            return true;
        if (matrix[i][j] > target)
            --j;
        else
            ++i;
    }
    return false;
}
