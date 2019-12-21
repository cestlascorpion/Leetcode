//
// Created by Wang on 2019/12/21.
//

#include "Leetcode1266cn.h"

/*
输入：points = [[1,1],[3,4],[-1,0]]
输出：7
解释：一条最佳的访问路径是： [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]
从 [1,1] 到 [3,4] 需要 3 秒
从 [3,4] 到 [-1,0] 需要 4 秒
一共需要 7 秒
*/

int Leetcode1266cn::minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int res = 0;
    for (int i = 1; i < points.size(); ++i) {
        int a = abs(points[i][0] - points[i - 1][0]);
        int b = abs(points[i][1] - points[i - 1][1]);
        res += min(a, b) + abs(a - b);
    }
    return res;
}
