//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode62.h"

int Leetcode62::uniquePaths2(int m, int n) {
    double ans = 1.0;
    for (int i = 0; i < n - 1; ++i) {
        double x = m + i;
        double y = n - 1 - i;
        ans = ans * x / y;
    }
    return round(ans);
}

void Leetcode62::test62() {
    cout << uniquePaths(5, 2) << " == 5" << endl;
}

int Leetcode62::uniquePaths(int m, int n) {
    if (m < 1 || n < 1)
        return 0;
    vector<int> ans(m, 0);
    ans[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[j] += (ans[j] + j > 0 ? ans[j - 1] : 0);
        }
    }
    return ans[m - 1];

}
