//
// Created by hans on 4/27/18.
//

#include "Leetcode326.h"

bool Leetcode326::isPowerOfThree(int n) {
    double tem = log10(n) / log10(3.0);
    if (int(tem) - tem == 0)
        return true;
    else
        return false;
}

bool Leetcode326::isPowerOfThree2(int n) {
    int base = 1;
    while (n != base) {
        base = base * 3;
        if (base > n)
            return false;
    }
    return true;
}

void Leetcode326::test326() {
    for (int i = 243; i <= 250; ++i) {
        cout << " for number " << i << " , ans is " << isPowerOfThree(i) << endl;
    }
}
