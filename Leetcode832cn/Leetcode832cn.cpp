//
// Created by Wang on 2019/12/4.
//

#include "Leetcode832cn.h"

vector<vector<int>> Leetcode832cn::flipAndInvertImage(vector<vector<int>> &A) {
    for (auto &vec : A) {
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            swap(vec[i], vec[j]);
            vec[i] = vec[i] == 0 ? 1 : 0;
            vec[j] = vec[j] == 0 ? 1 : 0;
            ++i;
            --j;
        }
        if (i == j) {
            vec[i] = vec[i] == 0 ? 1 : 0;
        }
    }
    return A;
}
