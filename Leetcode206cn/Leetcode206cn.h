//
// Created by Wang on 2019/10/13.
//

#ifndef LEETCODE_LEETCODE206CN_H
#define LEETCODE_LEETCODE206CN_H

#include <config.h>

class Leetcode206cn {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return  nullptr;

        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur->next != nullptr) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        cur->next = pre;
        return cur;
    }
};


#endif //LEETCODE_LEETCODE206CN_H
