//
// Created by hans on 4/26/18.
//

#include "Leetcode237.h"

void Leetcode237::test237() {
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    deleteNode(head->next);
    for (ListNode *p = head; p!= nullptr; p = p->next)
        cout << p->val << " ";
    //memory leak
}

void Leetcode237::deleteNode(ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
