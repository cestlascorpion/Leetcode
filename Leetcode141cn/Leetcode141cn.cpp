//
// Created by Wang on 2019/10/13.
//

#include "Leetcode141cn.h"

bool Leetcode141cn::hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return false;

    ListNode *s = head;
    ListNode *f = head->next;

    while (f != nullptr && f->next != nullptr) {
        if (s == f) {
            return true;
        }
        s = s->next;
        f = f->next->next;
    }
    return false;
}
