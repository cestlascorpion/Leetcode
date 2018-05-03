//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode572.h"

bool Leetcode572::isSubtree(TreeNode *s, TreeNode *t) {
    if (s == nullptr)
        return false;
    if (isSametree(s, t)) //检查两棵树否相同
        return true;
    //不相同检查左子树和右子树是否和t相同
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

bool Leetcode572::isSametree(TreeNode *s, TreeNode *t) {
    if (s == nullptr && t == nullptr)
        return true;
    if (s == nullptr || t == nullptr)
        return false;
    else
        return s->val == t->val &&
               isSametree(s->left, t->left)
               && isSametree(s->right, t->right);

}
