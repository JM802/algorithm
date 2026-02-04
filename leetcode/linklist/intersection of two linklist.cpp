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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *cura = headA;
        ListNode *curb = headB;
        int lena = 0;
        int lenb = 0;

        while(cura)
        {
            lena++;
            cura = cura->next;
        }

        while(curb)
        {
            lenb++;
            curb = curb->next;
        }
        cura = headA;
        curb = headB;

        if(lenb>lena)
        {
            swap(lena, lenb);
            swap(headA, headB);
            cura = headA;
            curb = headB;
        }
        int gap = lena - lenb;

        while(gap>0)
        {
            cura = cura->next;
            gap--;
        }

        while(cura&&curb)
        {
            if(cura==curb)
            {
                return cura;
            }
            cura = cura->next;
            curb = curb->next;
        }
        return nullptr;
    }
};