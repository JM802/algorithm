#include<iostream>
#include<stack>
#include<vector>
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
    //中左右（前序遍历）
    vector<int> iterative_travesal_pre(TreeNode*root)
    {
        vector<int>res={};
        stack<TreeNode*> st;
        if(!root)
        {
            return {};
        }

        st.push(root);

        while(!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            res.push_back(cur->val);//中
            if(cur->right)
            {
                st.push(cur->right);//右
            }
            if(cur->left)
            {
                st.push(cur->left);//左
            }
            //由于是栈，为中左右
        }
        return res;
    }

    //左右中(后序遍历)
    vector<int> iterative_travesal_post(TreeNode *root)
    {
        vector<int> res = {};
        stack<TreeNode *> st;
        if (!root)
        {
            return {};
        }

        st.push(root);

        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            res.push_back(cur->val);//中
            if (cur->left)
            {
                st.push(cur->left);//左
            }
            if (cur->right)
            {
                st.push(cur->right);//右
            }
            //由于是栈，为中右左
        }
        reverse(res.begin(), res.end());
        return res;
    }

    //中序遍历（左中右）
    vector<int> iterative_travesal_inorder(TreeNode*root)
    {
        vector<int> res = {};
        stack<TreeNode*> st;
        if(!root)
        {
            return {};
        }

        TreeNode *cur = root;

        while(!cur||!st.empty())
        {
            if(!cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                res.push_back(cur->val);
                st.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};
