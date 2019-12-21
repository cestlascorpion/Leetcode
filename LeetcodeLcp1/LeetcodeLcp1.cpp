//
// Created by Wang on 2019/12/21.
//

#include "LeetcodeLcp1.h"

int LeetcodeLcp1::game(vector<int> &guess, vector<int> &answer) {
    int count = 0;
    for (int i = 0; i < 3; ++i) {
        if (guess[i] == answer[i]) {
            ++count;
        }
    }
    return count;
}
