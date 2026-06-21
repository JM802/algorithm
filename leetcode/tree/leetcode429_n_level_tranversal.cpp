#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(Node *root)
    {
        if(!root)
        {
            return {};
        }

        queue<Node *> q;
        vector<vector<int>> res;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; i++)
            {
                Node *cur = q.front();
                q.pop();
                v.push_back(cur->val);  
                for (int j = 0; j < cur->children.size();j++)
                {
                    if(cur->children[j])
                    {
                        q.push(cur->children[j]);
                    }
                }
            }
            res.push_back(v);
        }
        return res;
    }
};