//
// Created by Wang on 2019/12/12.
//

#include "Leetcode859cn.h"

bool Leetcode859cn::buddyStrings(string A, string B) {
    if (A.size() != B.size())
        return false;
    int low = 0;
    int high = A.size() - 1;
    while (low < high && A[low] == B[low])
        ++low;
    while (low < high && A[high] == B[high])
        --high;
    if (low == high) {
        if (A[low] != A[high])
            return false;
        return contain_duplicate(A);
    }

    swap(A[low], A[high]);
    while (low < high && A[low] == B[low])
        ++low;
    while (low < high && A[high] == B[high])
        --high;
    return low == high && A[low] == B[low];
}
