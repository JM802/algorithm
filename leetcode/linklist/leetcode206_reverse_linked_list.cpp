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
    // ListNode* reverse(ListNode*pre,ListNode*cur)
    // {
    //     if(cur==nullptr)
    //     {
    //         return pre;
    //     }
    //     ListNode *temp = cur->next;
    //     cur->next = pre;
    //     return reverse(cur, temp);
    // }
    ListNode *reverseList(ListNode *head)
    {
        // ListNode *pre = nullptr;
        // ListNode *cur = head;
        // while(cur)
        // {
        //     ListNode*temp=cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = temp;
        // }
        // return pre;

        // return reverse(nullptr, head);

        if(head==nullptr)
        {
            return nullptr;
        }
        if(head->next==nullptr)
        {
            return head;
        }

        ListNode *last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};