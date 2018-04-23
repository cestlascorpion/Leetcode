#include "000.config.h"

class Solution
{
  public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return head;
        else
        {
            ListNode *previous = head;      //反转后，下一个节点指向当前节点
            ListNode *current = head->next; //指向下一节点（current的next应该指回previous）
            head->next = NULL;              //反转后第一个节点的下一节点为空节点
            while (current != NULL)
            {
                ListNode *temp = previous; //保存需要指回的节点
                previous = current;        //previous移动 指向当前节点
                current = current->next;   //current移动 指向当前节点的下一节点
                previous->next = temp;     //previous->next 指回上一节点
            }
            return previous; //如果current==NULL 返回最后操作的节点地址
        }
    }
};