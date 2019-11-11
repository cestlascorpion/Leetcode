#include <Leetcode236cn/Leetcode236cn.h>
#include <config.h>
void test() {
    TreeNode p0(0);
    TreeNode p1(1);
    TreeNode p2(2);
    TreeNode p3(3);
    TreeNode p4(4);
    TreeNode p5(5);
    TreeNode p6(6);
    TreeNode *p = &p0;
    p0.left = &p1;
    p0.right = &p2;
    p1.left = &p3;
    p1.right = &p4;
    p2.left = &p5;
    p2.right = &p6;
    Leetcode236cn sol;
    cout << sol.lowestCommonAncestor(&p0, &p2, &p6)->val << endl;
}

int main() {
    test();
    return 0;
}
