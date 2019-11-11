//
// Created by Wang on 2019/11/10.
//

#include "Leetcode148cn.h"

ListNode *Leetcode148cn::sortList(ListNode *head) {
    if (head == nullptr)
        return nullptr;

    quick_sort(head, nullptr);
    return head;
}

void Leetcode148cn::quick_sort(ListNode *head, ListNode *tail) {
    if (head != tail) {
        ListNode *middle = helper(head, tail);
        quick_sort(head, middle);
        quick_sort(middle->next, tail);
    }
}

ListNode *Leetcode148cn::helper(ListNode *head, ListNode *tail) {
    int val = head->val;
    ListNode *cursor = head->next;
    ListNode *middle = head;
    while (cursor != tail) {
        if (cursor->val < val) {
            middle->val = cursor->val;
            middle = middle->next;
            cursor->val = middle->val;
            cursor = cursor->next;
        } else {
            cursor = cursor->next;
        }
    }
    middle->val = val;
    return middle;
}

ListNode *Leetcode148cn::sortList2(ListNode *head) {
    if (head == nullptr)
        return nullptr;
    auto cmp = [](ListNode *p1, ListNode *p2) -> bool { return p1->val < p2->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
    while (head != nullptr) {
        pq.push(head);
        head = head->next;
    }
    ListNode *pre = nullptr;
    while (!pq.empty()) {
        ListNode *p = pq.top();
        p->next = pre;
        pre = p;
        pq.pop();
    }
    return pre;
}

ListNode *Leetcode148cn::sortList3(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    return merge_sort(head);
}

ListNode *Leetcode148cn::merge_sort(ListNode *head) {
    if (head->next == nullptr) {
        return head;
    }
    ListNode *pHead = head, *qHead = head, *pre = nullptr;
    while (qHead != nullptr && qHead->next != nullptr) {
        qHead = qHead->next->next;
        pre = pHead;
        pHead = pHead->next;
    }
    pre->next = nullptr; // split
    ListNode *l, *r;
    l = merge_sort(head);
    r = merge_sort(pHead);
    return do_merge(l, r);
}

ListNode *Leetcode148cn::do_merge(ListNode *l, ListNode *r) {
    ListNode fake = ListNode(0);
    ListNode *temp = &fake;
    while (l != nullptr && r != nullptr) {
        if (l->val <= r->val) {
            temp->next = l;
            temp = temp->next;
            l = l->next;
        } else {
            temp->next = r;
            temp = temp->next;
            r = r->next;
        }
    }
    if (l != nullptr)
        temp->next = l;
    if (r != nullptr)
        temp->next = r;
    return fake.next;
}
