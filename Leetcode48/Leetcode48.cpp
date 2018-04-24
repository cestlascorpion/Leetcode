//
// Created by hans on 18-4-24.
//

#include "Leetcode48.h"

void Leetcode48::rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

void Leetcode48::test48() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};
    vector<int> v3 = {7, 8, 9};
    vector<vector<int>> matrix = {v1, v2, v3};
    rotate(matrix);
    for (auto item : matrix) {
        for (auto jtem:item) {
            cout << jtem << " ";
        }
        cout << endl;
    }
    cout << endl;
}
