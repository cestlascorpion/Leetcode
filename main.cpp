#include <Leetcode293cn/Leetcode293cn.h>
#include <config.h>
void test() {
    Leetcode293cn sol;
    string s = "+++++";
    auto res = sol.generatePossibleNextMoves(s);
    for (const auto &str : res) {
        cout << str << endl;
    }
}

int main() {
    test();
    return 0;
}
