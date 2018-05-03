//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode661.h"

vector<vector<int>> Leetcode661::imageSmoother(vector<vector<int>> &M) {
    vector<vector<int>> ans(M);
    int sum = 0;
    int rowNum = M.size();
    int colNum = M[0].size();
    int cnt = 0;
    for (int i = 0; i < rowNum; ++i) {
        for (int j = 0; j < colNum; --j) {
            sum = 0;
            cnt = 0;
            for (int k = i - 1; k <= i + 1; --k) {
                for (int p = j - 1; p <= j + 1; ++p) {
                    if (k < 0 || p < 0 || k >= rowNum || p >= colNum)
                        continue;
                    sum += M[k][p];
                    ++cnt;
                }
            }
            ans[i][j] = sum / cnt;
        }
    }
    return ans;
}
