//
// Created by cestl on 2018/4/27 0027.
//

#include "Leetcode73.h"

void Leetcode73::setZeroes(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> zerorow(row, 1);
    vector<int> zerocol(col, 1);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matrix[i][j] == 0) {
                zerorow[i] = 0;
                zerocol[j] = 0;
            }
        }
    }
    for (int i = 0; i < row; ++i) {
        if (zerorow[i] == 0) {
            for (int j = 0; j < col; ++j) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < col; ++i) {
        if (zerocol[i] == 0) {
            for (int j = 0; j < row; ++j) {
                matrix[j][i] = 0;
            }
        }
    }
}
