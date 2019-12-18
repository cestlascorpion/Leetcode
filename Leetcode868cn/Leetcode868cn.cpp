//
// Created by Wang on 2019/12/18.
//

#include "Leetcode868cn.h"

int Leetcode868cn::binaryGap(int N) {
    int last = -1, ans = 0;
    for (int i = 0; i < 32; ++i)
        if (((N >> i) & 1) > 0) {
            if (last >= 0)
                ans = max(ans, i - last);
            last = i;
        }
    return ans;
}
