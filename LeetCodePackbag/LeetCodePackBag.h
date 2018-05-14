//
// Created by cestl on 2018/5/14 0014.
//

#ifndef LEETCODE_LEETCODEPACKBAG_H
#define LEETCODE_LEETCODEPACKBAG_H

#include "../config.h"

#define Number 5
#define Space 12

class LeetCodePackBag {
public:
    //01背包问题是在前一个子问题（i-1种物品）的基础上来解决当前问题（i种物品）
    //向i-1种物品时的背包添加第i种物品
    //ans[i][j] = max{ans[i-1][j], ans[i-1][j-weight[i]]+value[i]}
    int ZeroOnePack() {
        int ans[Number + 1][Space + 1] = {{0}};      //保存在 F[i][j]
        //在决定是否防止第i个物品，使用容量为j时的最优解
        int value[Number + 1] = {0, 2, 5, 3, 10, 4}; //物品的价值
        int weight[Number + 1] = {0, 1, 3, 2, 6, 2}; //物品所占用的空间
        int maxSpace = Space;

        for (int i = 1; i <= Number; ++i) {
            for (int j = 1; j <= maxSpace; ++j) {
                if (j < weight[i])             //可用容量j小于想要放入背包的物品i的体积
                    ans[i][j] = ans[i - 1][j]; //不放入物品i，F[i][i]等于上次的相同容量j的最优解
                else
                    ans[i][j] = max(ans[i - 1][j],              //不放入物品i，即上一次相同容量 j 的最优解
                                    ans[i - 1][j - weight[i]] + //放入物品 i（所以需要为物品 i 腾出空间）
                                    value[i]);              //取上一次容量为 j-weight[i] 的最优解 + 物品 i 的 value[i]
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
        cout << ans[Number][Space] << endl; //遍历完所有物品，并达到最大容量时，为全局的最优解

        return 0;
    }

    void ZeroOnePack2() {
        int ans[Space + 1] = {0}; //只保存上次遍历物品 i 时，所有容量 j 下的最优解
        //ans[1~Space]初始化为 0，表示背包可以不放满
        //ans[1~Space]初始化为 INT_MIN，表示背包必须放满
        int value[Number + 1] = {0, 2, 5, 3, 10, 4};
        int weight[Number + 1] = {0, 1, 3, 2, 6, 2};
        int maxSpace = Space;
        for (int i = 1; i <= Number; ++i) {
            for (int j = maxSpace; j >= weight[i]; --j)
                //从后向前保证不会重复放入物品 i
                ans[j] = max(ans[j], ans[j - weight[i]] + value[i]);
        }
        cout << ans[maxSpace] << endl;
    }

    //完全背包问题是在解决当前问题（i种物品）
    //向i种物品时的背包添加第i种物品
    //ans[i][j] = max of (ans[i-1][j-k*weight[i]]+k*value[i], 0<=k*weight[i]<=maxSpace)
    void CompletePack() {
        int ans[Space + 1] = {0}; //只保存上次遍历物品 i 时，所有容量 j 下的最优解
        //ans[1~Space]初始化为 0，表示背包可以不放满
        //ans[1~Space]初始化为 INT_MIN，表示背包必须放满
        int value[Number + 1] = {0, 2, 5, 3, 10, 4};
        int weight[Number + 1] = {0, 1, 3, 2, 6, 2};
        int maxSpace = Space;
        for (int i = 1; i <= Number; ++i) {
            for (int j = weight[i]; j <= maxSpace; ++j) {
                //从前向后保证可以重复放入物品 i
                ans[j] = max(ans[j], ans[j - weight[i]] + value[i]);
            }
        }
        cout << ans[maxSpace] << endl;
    }

    //ans[i][j] = max{ans[i-1][j-k*weight[i]]+k*value[i]} ,其中(0<=k<=min{j/weight[i], num[i]})
    void MultiplePack() {
        int ans[Space + 1] = {0}; //只保存上次遍历物品 i 时，所有容量 j 下的最优解
        //ans[1~Space]初始化为 0，表示背包可以不放满
        //ans[1~Space]初始化为 INT_MIN，表示背包必须放满
        int value[Number + 1] = {0, 2, 5, 3, 10, 4};
        int weight[Number + 1] = {0, 1, 3, 2, 6, 2};
        int num[Number + 1] = {0, 4, 7, 2, 4, 6};
        int maxSpace = Space;
        for (int i = 1; i <= Number; ++i) {
            if (num[i] * weight[i] >= maxSpace) //将物品 i 全部放入会超重，所以可以将物品 i 视为无限个
                for (int j = weight[i]; j <= maxSpace; ++j)
                    ans[j] = max(ans[j], ans[j - weight[i]] + value[i]);
            else {
                int k = 1; //遍历每种取法，利用到二进制思想，降低复杂度 ( O(k)-> O(logk) )
                //取的1,2,4,8...与余数个该物品，打包成一个大型的该物品
                //如k = 11，则有1,2,4,...4
                while (k < num[i]) {
                    for (int j = maxSpace; j >= k * weight[i]; --j) //放入k个物品 i
                        ans[j] = max(ans[j], ans[j - k * weight[i]] + k * value[i]);
                    num[i] = num[i] - k;
                    k = k * 2;
                } //1,2,4,8...
                for (int j = maxSpace; j >= num[i] * weight[i]; --j)
                    ans[j] = max(ans[j], ans[j - num[i] * weight[i]] + num[i] * value[i]);
            }
        }
        cout << ans[maxSpace] << endl;
    }
};


#endif //LEETCODE_LEETCODEPACKBAG_H
