//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode263.h"

int Leetcode263::ugly(int n) {
    if (n <= 0)
        return 0;
    vector<int> uglynum(n, 0);
    uglynum[0] = 1;
    int next = 1;
    int p2 = 0;
    int p3 = 0;
    int p5 = 0;
    while (next < n) {
        int minnum = min(uglynum[p2] * 2, min(uglynum[p3] * 3, uglynum[p5] * 5));
        uglynum[next] = minnum;
        while (uglynum[p2] * 2 <= uglynum[next])
            ++p2;
        while (uglynum[p3] * 3 <= uglynum[next])
            ++p3;
        while (uglynum[p5] * 5 <= uglynum[next])
            ++p5;
    }
    int ans = uglynum[next - 1];
    return ans;
}
