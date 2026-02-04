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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        n = n + 1;
        while (fast != nullptr &&n>0)
        {
            fast = fast->next;
            n--;
        }
        while(fast!=nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp1 = slow->next;
        slow->next = slow->next->next;
        delete temp1;

        ListNode *temp2 = dummy;
        ListNode *res = dummy->next;
        delete temp2;
        return res;
    }
};