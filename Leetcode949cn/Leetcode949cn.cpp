//
// Created by Wang on 2019/10/13.
//

#include "Leetcode949cn.h"

string Leetcode949cn::largestTimeFromDigits(vector<int> &A) {
    vector<int> res = A;
    int comp = INT_MIN;
    sort(A.begin(), A.end());
    do {
        int tmp = get_minutes(A);
        if (tmp > comp) {
            res = A;
            comp = tmp;
        }
    } while (next_permutation(A.begin(), A.end()));
    if (comp == INT_MIN) {
        return "";
    }
    return to_string(res[0]) + to_string(res[1]) + ":" + to_string(res[2]) + to_string(res[3]);
}

int Leetcode949cn::get_minutes(const vector<int> &A) {
    if ((A[0] > 2) || (A[0] == 2 && A[1] > 3) || A[2] > 5) {
        return INT_MIN;
    }
    return A[0] * 600 + A[1] * 60 + A[2] * 10 + A[3];
}
