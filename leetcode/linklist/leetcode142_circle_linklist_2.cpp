#include <iostream>
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!=nullptr&&fast->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
            {
                ListNode *cur1 = head;
                ListNode *cur2 = slow;
                while (cur1 != cur2)
                {
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                }
                return cur1;
            }
        }
        return nullptr;
    }
};