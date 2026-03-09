#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;

    TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}

    TreeNode(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    TreeNode(int _val, TreeNode *_left, TreeNode *_right, TreeNode *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    int getheight(TreeNode*root)
    {
        if(!root)
        {
            return 0;
        }
        int leftheight = getheight(root->left);
        if(leftheight==-1)
        {
            return -1;
        }
        int rightheight = getheight(root->right);
        if(rightheight==-1)
        {
            return -1;
        }

        int res;
        if(abs(leftheight-rightheight)>1)
        {
            res = -1;
        }
        else
        {
            res = max(leftheight, rightheight) + 1;
        }
        return res;
    }

    bool isBalanced(TreeNode *root)
    {
        int res=getheight(root);
        if(res==-1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};