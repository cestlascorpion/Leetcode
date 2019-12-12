//
// Created by Wang on 2019/12/12.
//

#include "Leetcode852cn.h"

int Leetcode852cn::peakIndexInMountainArray(vector<int> &A) {
    assert(A.size() >= 3);

    int low = 0;
    int high = A.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
            return mid;
        }
        if (A[mid] > A[mid - 1]) {
            low = mid + 1;
        } else {
            high = mid ;
        }
    }
    return -1;
}
