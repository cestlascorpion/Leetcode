//
// Created by Wang on 2019/10/29.
//

#include "Leetcode61cn.h"

ListNode *Leetcode61cn::rotateRight(ListNode *head, int k) {
    if (head == nullptr) {
        return nullptr;
    }
    if (k <= 0) {
        return head;
    }

    ListNode *p = head;
    int n = 0;
    do {
        ++n;
        p = p->next;
    } while (p != nullptr);
    k = k % n;

    ListNode *q = head;
    if (k == 0)
        return head;

    while (k > 0) {
        q = q->next;
        --k;
    }
    p = head;

    while (q->next != nullptr) {
        p = p->next;
        q = q->next;
    }
    q->next = head;
    ListNode* r = p->next;
    p->next = nullptr;
    return r;
}
