#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    void preordertool(Node*root,vector<int>&res)
    {
        if(!root)
        {
            return;
        }
        res.push_back(root->val);
        for (int i = 0;i<root->children.size();i++)
        {
            preordertool(root->children[i], res);
        }
        return;
    }

    vector<int> preorder(Node *root)
    {
        vector<int> res = {};
        preordertool(root, res);
        return res;
    }
};