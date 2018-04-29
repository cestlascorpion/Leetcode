//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode203.h"

ListNode *Leetcode203::removeElements(ListNode *head, int val) {
    if (head == nullptr)
        return nullptr;

    while (head->val == val) {
        head = head->next;
        if (head == nullptr)
            return nullptr;
    }

    ListNode *p = head;
    while (p->next != nullptr) {
        if (p->next->val == val)
            p->next = p->next->next;
        else
            p = p->next;
    }
    return head;
}
