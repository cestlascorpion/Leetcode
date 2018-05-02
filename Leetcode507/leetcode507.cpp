//
// Created by cestl on 2018/5/2 0002.
//

#include "leetcode507.h"

bool leetcode507::checkPerfectNumber(int num) {
    if (num <= 0)
        return false;
    int sum = 0;
    for (int i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num)
                sum += num / i;
        }
    }
    return sum - num == num;
}
