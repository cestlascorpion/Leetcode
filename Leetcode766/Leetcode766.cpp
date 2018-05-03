//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode766.h"

bool Leetcode766::isToeplitzMatrix(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty())
        return true;

    int m = matrix.size();
    int n = matrix[0].size();


    for (int i = m - 2; i >= 0; --i) {
        int num = matrix[i][0];
        for (int j = 1; j <= n - 1 && j <= (m - 1) - i; ++j) {
            if (matrix[i + j][j] != num)
                return false;
        }
    }
    for (int i = n - 2; i >= 1; --i) {
        int num = matrix[0][i];
        for (int j = 1; j <= m - 1 && j <= (n - 1) - i; ++j) {
            if (matrix[j][i + j] != num)
                return false;
        }
    }
    return true;
}
