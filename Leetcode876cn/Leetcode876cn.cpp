//
// Created by Wang on 2019/12/4.
//

#include "Leetcode876cn.h"

ListNode *Leetcode876cn::middleNode(ListNode *head) {
    if (head == nullptr)
        return nullptr;

    ListNode *f = head;
    ListNode *s = head;
    while (f->next != nullptr) {
        f = f->next->next;
        s = s->next;
        if (f == nullptr) {
            break;
        }
    }
    return s;
}
