//
// Created by Wang on 2019/12/21.
//

#include "Leetcode1009cn.h"

int Leetcode1009cn::bitwiseComplement(int N) {
    int temp = 2;
    while (temp <= N) {
        temp = temp << 1;
    }
    return temp - N - 1;
}
