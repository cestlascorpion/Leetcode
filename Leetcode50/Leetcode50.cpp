//
// Created by cestl on 2018/5/4 0004.
//

#include "Leetcode50.h"

double Leetcode50::myPow(double x, int n) {
    if (n == 0)
        return 1.0;
    if (n < 0) {
        if (n == INT32_MIN)
            return 1.0 / (pow(x, INT32_MAX) * x);
        else
            return 1.0 / pow(x, -n);
    } else {
        if (n % 2 == 0) {
            double temp = myPow(x, n >> 1);
            return temp * temp;
        } else {
            double temp = myPow(x, (n - 1) >> 1);
            return temp * temp * x;
        }
    }
}
