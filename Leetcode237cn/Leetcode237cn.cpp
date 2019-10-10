//
// Created by Wang on 2019/10/13.
//

#include "Leetcode237cn.h"

void Leetcode237cn::deleteNode(ListNode *node) {
    if (node == nullptr) {
        return;
    }

    ListNode *del = node->next;
    node->val = del->val;
    node->next = del->next;
    delete del;
}
