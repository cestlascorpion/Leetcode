#include "Leetcode922cn/Leetcode922cn.h"

void test() {
    Leetcode922cn sol;
    vector<int> A{1, 4, 2, 0, 5};
    auto res = sol.sortArrayByParityII(A);
    for (const auto &a : res) {
        cout << a << endl;
    }
}

int main() {
    test();
    return 0;
}
