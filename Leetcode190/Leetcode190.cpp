//
// Created by hans on 4/27/18.
//

#include "Leetcode190.h"

uint32_t Leetcode190::reverseBits(uint32_t n) {
    uint32_t ans = 0;
    uint32_t mask = 1;
    for (uint32_t i = 0; i < 32; ++i) {
        ans = (ans << 1) | ((n & mask) >> i);
        mask <<= 1;
    }
    return ans;
}

void Leetcode190::test190() {
    uint32_t num =43261596;
    cout << num << " -> " << reverseBits(num) << endl;
}
