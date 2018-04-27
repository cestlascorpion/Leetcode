//
// Created by hans on 4/27/18.
//

#include "Leetcode461.h"

int Leetcode461::hammingDistance(int x, int y) {
    int cal = x ^y;
    int ans = 0;
    while (cal != 0) {
        ++ans;
        cal = cal & (cal - 1);
    }
    return ans;
}

void Leetcode461::test461() {
    vector<pair<int, int>> p{{1, 2},
                             {1, 4}};
    for (auto item : p) {
        cout << " the hammingDistance of " << item.first << " and " << item.second << " is "
             << hammingDistance(item.first, item.second) << endl;
        cout << endl;

    }
}
