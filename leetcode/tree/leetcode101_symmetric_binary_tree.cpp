#include<iostream>
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

    bool compare(TreeNode*left,TreeNode*right)
    {
        if(!left&&right)
        {
            return false;
        }
        else if(left&&!right)
        {
            return false;
        }
        else if(!left&&!right)
        {
            return true;
        }
        else if(left&&right&&left->val!=right->val)
        {
            return false;
        }
        bool outside = compare(left->left,right->right);
        bool inside = compare(left->right,right->left);
        bool issame = outside && inside;
        return issame;
    }
    bool isSymmetric(TreeNode *root)
    {
        if(!root)
        {
            return false;
        }
        return compare(root->left, root->right);
    }
};