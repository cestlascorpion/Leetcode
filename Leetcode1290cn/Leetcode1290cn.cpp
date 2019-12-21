//
// Created by Wang on 2019/12/21.
//

#include "Leetcode1290cn.h"

int Leetcode1290cn::getDecimalValue(ListNode *head) {
    int res = 0;
    while (head != nullptr) {
        res = res << 1;
        res += (head->val);
        head = head->next;
    }
    return res;
}
