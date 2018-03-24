#include "0. config.h"

class Solution
{
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode *cur1 = headA, *cur2 = headB;
        while (cur1 != cur2)
        {
            cur1 = cur1 ? cur1->next : headB;
            cur2 = cur2 ? cur2->next : headA;
        }
        return cur1; //并不会出现无限循环的问题，没有交叉则会在第二次重定向前在NULL指针处相等并返回NULL
    }
};
//假设AB有交叉 交叉长度为c 除去交叉部分AB长度分别为ab
//a+c+b +c
//b+c+a +c
//因此在走过a+b+c长度后会在c相遇，也是需要返回的交叉点
//而且会同时走完
class Solution2
{
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        //ListA和ListB至少有一个元素

        //遍历ListA 记录尾指针 修改末尾元素指向起始元素形成环 lengthA为环的长度
        ListNode *tailA = NULL;
        ListNode *head = headA;
        int lengthA = 0;
        while (head != NULL)
        {
            if (head->next == NULL)
            {
                lengthA++;
                tailA = head;
                head->next = headA;
                break;
            }
            lengthA++;
            head = head->next;
        }

        //遍历ListB fast和slow两个指针 如果在遍历结束前相遇 说明有环 即ListA和ListB交叉
        ListNode *fastB = headB;
        ListNode *slowB = headB;
        while (fastB != NULL && fastB->next != NULL)
        {
            slowB = slowB->next;
            fastB = fastB->next->next;
            if (fastB == slowB)
                break;
        }
        if (fastB == NULL || fastB->next == NULL)
        {
            tailA->next = NULL;
            return NULL;
        }
        else
        {
            fastB = headB;
            slowB = headB;
            for (int i = 0; i < lengthA; i++)
            {
                fastB = fastB->next;
            }
            while (fastB != slowB)
            {
                fastB = fastB->next;
                slowB = slowB->next;
            }
            tailA->next = NULL;
            return slowB;
        }
    }
};