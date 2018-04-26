//
// Created by hans on 4/26/18.
//

#ifndef LEETCODE_LEETCODE234_H
#define LEETCODE_LEETCODE234_H

#include "../config.h"

class Leetcode234 {
public:
    bool isPalindrome(ListNode *head);
    void test234();

private:
    ListNode* reverseList(ListNode* head);
};


#endif //LEETCODE_LEETCODE234_H
