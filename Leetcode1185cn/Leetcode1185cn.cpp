//
// Created by Wang on 2019/10/10.
//

#include "Leetcode1185cn.h"


string Leetcode1185cn::dayOfTheWeek(int day, int month, int year) {
    const vector<string> dict = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    // 基姆拉尔森计算公式
    // 注意：在公式中有个与其他公式不同的地方：
    // 把一月和二月看成是上一年的十三月和十四月，例：如果是2004-1-10则换算成：2003-13-10来代入公式计算。
    if (month == 1 || month == 2) {
        month += 12;
        --year;
    }
    int res = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    return dict[res];
}
