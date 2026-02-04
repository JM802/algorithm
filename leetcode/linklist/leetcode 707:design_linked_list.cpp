#include <iostream>
using namespace std;

class linknode
{
public:
    int val;
    linknode *next;
    linknode(int v)
    {
        val = v;
        next = nullptr;
    }
};

class MyLinkedList
{
public:
    int size;
    linknode *dummy;
    MyLinkedList()
    {
        size = 0;
        dummy = new linknode(-1);
    }

    int get(int index)
    {
        if (index < 0 || index > size - 1)
        {
            return -1;
        }

        linknode *cur = dummy->next;
        while (index > 0)
        {
            cur = cur->next;
            index--;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        linknode *newnode = new linknode(val);
        newnode->next = dummy->next;
        dummy->next = newnode;
        size++;
    }

    void addAtTail(int val)
    {
        linknode *newnode = new linknode(val);
        linknode *cur = dummy;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newnode;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        linknode *newnode = new linknode(val);
        if (index > size)
        {
            return;
        }

        linknode *cur = dummy;

        while (index > 0)
        {
            cur = cur->next;
            index--;
        }
        newnode->next = cur->next;
        cur->next = newnode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index > size - 1)
        {
            return;
        }

        linknode *cur = dummy;
        while (index > 0)
        {
            cur = cur->next;
            index--;
        }
        linknode *temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        size--;
    }
};
