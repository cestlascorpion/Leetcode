//
// Created by hans on 4/26/18.
//

#include "Leetcode77.h"

ListNode *Leetcode77::reverseList(ListNode *head) {
    if (head == nullptr)
        return nullptr;
    stack<ListNode *> s;
    ListNode *p = head;
    while (p != nullptr) {
        s.push(p);
        p = p->next;
    }
    head = s.top();
    p = head;
    s.pop();
    while (!s.empty()) {
        p->next = s.top();
        s.pop();
        p = p->next;
    }
    p->next = nullptr;
    return head;
}

ListNode *Leetcode77::reverseList2(ListNode *head) {
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

void Leetcode77::test77() {
    ListNode p1(0);
    ListNode p2(1);
    ListNode p3(2);
    p1.next = &p2;
    p2.next = &p3;
    ListNode *p = &p1;
    ListNode *ans = reverseList(p);
    while (ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
}
