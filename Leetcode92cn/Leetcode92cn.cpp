//
// Created by Wang on 2019/10/28.
//

#include "Leetcode92cn.h"

ListNode *Leetcode92cn::reverseBetween(ListNode *head, int m, int n) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *m_pre = nullptr;
    ListNode *n_nxt = head->next;
    ListNode *pm = head;
    ListNode *pn = head;
    --m;
    --n;
    while (n > 0) {
        if (m > 0) {
            m_pre = pm;
            pm = pm->next;
            --m;
        }
        pn = pn->next;
        n_nxt = pn == nullptr ? nullptr : pn->next;
        --n;
    }
    if (m_pre != nullptr) {
        m_pre->next = reverse(pm, pn);
        pm->next = n_nxt;
    } else {
        head = reverse(pm, pn);
        pm->next = n_nxt;
    }
    return head;
}

ListNode *Leetcode92cn::reverse(ListNode *head, ListNode *tail) {
    assert(head != nullptr);

    ListNode *pre = nullptr;
    while (head != tail) {
        ListNode *tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
    }
    if (head == nullptr) {
        return pre;
    } else {
        head->next = pre;
        return head;
    }
}
