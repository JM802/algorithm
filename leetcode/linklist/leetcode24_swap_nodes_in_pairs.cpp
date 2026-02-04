#include<iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int v)
    {
        val = v;
        next = nullptr;
    }
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        while(cur->next!=nullptr&&cur->next->next!=nullptr)
        {
            ListNode *temp1 = cur->next;
            ListNode*temp2=cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = temp1;
            temp1->next = temp2;
            cur = cur->next->next;
        }
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};