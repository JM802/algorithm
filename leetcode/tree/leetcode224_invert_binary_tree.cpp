#include <iostream>
#include <stack>
#include <vector>
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
    TreeNode *invertTree(TreeNode *root)
    {
        if(!root)
        {
            return nullptr;
        }

        TreeNode *leftroot = invertTree(root->left);
        TreeNode *rightroot = invertTree(root->right);
        root->left=rightroot;
        root->right=leftroot;

        return root;
    }
};