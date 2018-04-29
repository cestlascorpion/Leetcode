//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode206.h"

ListNode *Leetcode206::reverseList(ListNode *head) {
    if (head == nullptr)
        return nullptr;

    ListNode *pre = head;       //反转后，下一个节点指向当前节点
    ListNode *cur = head->next; //指向下一节点（current的next应该指回previous）
    head->next = nullptr;       //反转后第一个节点的下一节点为空节点
    while (cur) {
        ListNode *temp = pre;   //保存需要指回的节点
        pre = cur;              //previous移动 指向当前节点
        cur = cur->next;        //current移动 指向当前节点的下一节点
        pre->next = temp;       //previous->next 指回上一节点
    }
    return pre;                 //如果current==nullptr 返回最后操作的节点地址
}
