//
// Created by hans on 4/26/18.
//

#include "Leetcode234.h"

bool Leetcode234::isPalindrome(ListNode *head) {
    if (head == nullptr)
        return true;
    ListNode *f = head;
    ListNode *s = head;
    while (f != nullptr && f->next != nullptr) {
        f = f->next->next;
        s = s->next;
    }
    ListNode *low = head;
    ListNode *high = reverseList(s);
    while (low && high) {
        if (low->val != high->val)
            return false;
        low=low->next;
        high=high->next;
    }
    return true;
}

void Leetcode234::test234() {


}

ListNode *Leetcode234::reverseList(ListNode *head) {
    if (head == nullptr)
        return nullptr;
    ListNode *pre = nullptr;
    ListNode *nxt = head->next;
    // 1       2       3     nil
    // pre   head     nxt
    while (nxt != nullptr) {
        head->next = pre;
        pre = head;
        head = nxt;
        nxt = nxt->next;
    }
    head->next = pre;
    return head;
}
