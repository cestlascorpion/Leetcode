//
// Created by Wang on 2019/11/10.
//

#include "Leetcode142cn.h"

ListNode *Leetcode142cn::detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            break;
        }
    }
    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }
    int n = 0;
    do {
        ++n;
        fast = fast->next;
    } while (fast != slow);

    fast = head;
    slow = head;
    while (n > 0) {
        --n;
        fast = fast->next;
    }
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
