//
// Created by Wang on 2019/10/13.
//

#include "Leetcode21cn.h"

ListNode *Leetcode21cn::mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
        return copy(l2);
    }
    if (l2 == nullptr) {
        return copy(l1);
    }

    ListNode *res = nullptr;
    if (l1->val < l2->val) {
        res = new ListNode(l1->val);
        l1 = l1->next;
    } else {
        res = new ListNode(l2->val);
        l2 = l2->next;
    }

    ListNode *cur = res;
    while (l1 != nullptr && l2 != nullptr) {
        ListNode *tmp = nullptr;
        if (l1->val < l2->val) {
            tmp = new ListNode(l1->val);
            l1 = l1->next;
        } else {
            tmp = new ListNode(l2->val);
            l2 = l2->next;
        }
        cur->next = tmp;
        cur = tmp;
    }
    if (l1 != nullptr) {
        cur->next = copy(l1);
    }
    if (l2 != nullptr) {
        cur->next = copy(l2);
    }

    return res;
}

ListNode *Leetcode21cn::copy(ListNode *l) {
    if (l == nullptr) {
        return nullptr;
    }

    auto *cur = new ListNode(l->val);
    ListNode *res = cur;
    while (l->next != nullptr) {
        l = l->next;
        auto *tmp = new ListNode(l->val);
        cur->next = tmp;
        cur = tmp;
    }
    return res;
}

ListNode *Leetcode21cn::mergeTwoLists_nocopy(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
        return l2;
    }

    if (l2 == nullptr) {
        return l1;
    }

    ListNode *res;
    if (l1->val < l2->val) {
        res = l1;
        l1 = l1->next;
    } else {
        res = l2;
        l2 = l2->next;
    }

    ListNode *cur = res;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    if (l1 != nullptr) {
        cur->next = l1;
    }
    if (l2 != nullptr) {
        cur->next = l2;
    }
    return res;
}
