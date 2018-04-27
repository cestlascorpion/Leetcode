//
// Created by hans on 4/27/18.
//

#include "Leetcode118.h"

vector<vector<int>> Leetcode118::generate(int numRows) {
    vector<vector<int>> ans;
    if (numRows < 1)
        return ans;

    vector<int> pre = {1};
    ans.push_back(pre);
    for (int i = 2; i <= numRows; i++) {
        vector<int> temp;
        for (int j = 0; j < i; j++) {
            if (j == 0)
                temp.push_back(1);
            else if (j == i - 1)
                temp.push_back(1);
            else
                temp.push_back((pre[j - 1] + pre[j]));
        }
        ans.push_back(temp);
        pre = temp;
    }
    return ans;
}

void Leetcode118::test118() {
    vector<vector<int>> ans = generate(5);
    for (auto item:ans) {
        for (auto jtem : item) {
            cout << jtem << " ";
        }
        cout << endl;
    }
    cout << endl;
}
