//
// Created by Wang on 2019/10/14.
//

#include "Leetcode23cn.h"

ListNode *Leetcode23cn::mergeKLists(vector<ListNode *> &lists) {
    ListNode fake(0);
    auto cmp = [](ListNode *l1, ListNode *l2) -> bool {
        // assert(l1 != nullptr && l2 != nullptr);
        return l1->val > l2->val;
    };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
    for (const auto node:lists) {
        if (node != nullptr)
            pq.push(node);
    }

    ListNode *p = &fake;
    while (!pq.empty()) {
        auto *tmp = pq.top();
        pq.pop();
        p->next = tmp;
        p = p->next;
        tmp = tmp->next;
        if (tmp != nullptr) {
            pq.push(tmp);
        }
    }
    return fake.next;
}

void Leetcode23cn::test() {
    ListNode p1(1);
    ListNode p2(2);
    ListNode p3(3);
    ListNode p4(4);
    ListNode p5(5);
    auto cmp = [](ListNode *l1, ListNode *l2) -> bool {
        if (l1 == nullptr) return true;
        if (l2 == nullptr) return false;
        return l1->val > l2->val;
    };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
    pq.push(&p1);
    pq.push(&p2);
    pq.push(&p3);
    pq.push(&p4);
    pq.push(&p5);
    pq.push(nullptr);
    pq.push(nullptr);

    while (!pq.empty()) {
        auto res = pq.top();
        if (res != nullptr) {
            cout << res->val;
        } else {
            cout << "null";
        }
        pq.pop();
    }
}
