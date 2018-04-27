//
// Created by hans on 4/27/18.
//

#include "Leetcode278.h"

int Leetcode278::firstBadVersion(int n) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid)) {
            if (mid == low || !isBadVersion(mid - 1))
                return mid;
            high = mid - 1;
        } else {
            if (mid == high || isBadVersion(mid + 1))
                return mid + 1;
            low = mid + 1;
        }
    }
    return -1;
}

void Leetcode278::test278() {
    int ans = firstBadVersion(12);
    cout << "bad version is " << ans << endl;
}
