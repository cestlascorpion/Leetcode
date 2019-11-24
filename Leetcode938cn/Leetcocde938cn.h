//
// Created by Wang on 2019/11/22.
//

#ifndef LEETCODE_LEETCOCDE938CN_H
#define LEETCODE_LEETCOCDE938CN_H

#include <config.h>

class Leetcocde938cn {
public:
    int rangeSumBST(TreeNode *root, int L, int R) {
        int res = 0;
        stack<TreeNode *> st;
        TreeNode *p = root;
        while (!st.empty() || p != nullptr) {
            if (p != nullptr) {
                st.push(p);
                p = p->left;
            } else {
                p = st.top();
                if (p->val >= L && p->val <= R) {
                    res += p->val;
                }
                if (p->val > R) {
                    break;
                }
                st.pop();
                p = p->right;
            }
        }
        return res;
    }
};


#endif //LEETCODE_LEETCOCDE938CN_H
