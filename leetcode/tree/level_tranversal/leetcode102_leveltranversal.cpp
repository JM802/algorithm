#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>
#include <cassert>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if(!root)
        {
            return {};
        }

        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size;i++)
            {
                TreeNode*cur=q.front();
                q.pop();
                v.push_back(cur->val);
                if(cur->left)
                {
                    q.push(cur->left);
                }
                if(cur->right)
                {
                    q.push(cur->right);
                }
            }
            res.push_back(v);
        }
        return res;
    }


    void tool_level(TreeNode*cur,int depth,vector<vector<int>>&res)
    {
        if(!cur)
        {
            return;
        }

        if(res.size()==depth)
        {
            res.push_back(vector<int>());
        }

        res[depth].push_back(cur->val);
        int newdepth = depth + 1;
        tool_level(cur->left, newdepth, res);
        tool_level(cur->right, newdepth, res);
    }

    vector<vector<int>> levelOrder1(TreeNode *root)
    {
        int depth = 0;
        vector<vector<int>> res;
        tool_level(root, depth, res);
        return res;
    }
};