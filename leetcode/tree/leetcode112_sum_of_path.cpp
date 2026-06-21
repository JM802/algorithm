#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
    bool getsum(TreeNode *root, int targetSum,int&sum)
    {
        if (!root)
        {
            return false;
        }

        sum += root->val;

        if (!root->left && !root->right)
        {
            if(targetSum==sum)
            {
                return true;
            }
            return false;
        }

        if(root->left)
        {
            if(getsum(root->left,targetSum,sum))
            {
                return true;
            }
            sum -= root->left->val;
        }
        if(root->right)
        {
            if (getsum(root->right, targetSum, sum))
            {
                return true;
            }
            sum -= root->right->val;
        }

        return false;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        bool res = getsum(root, targetSum, sum);
        return res;
    }

    bool getsum1(TreeNode*root,int targetSum,int sum)
    {
        if(!root->left&&!root->right)
        {
            if(sum==targetSum)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        if(root->left)
        {
            if(getsum1(root,targetSum,sum+root->left->val))
            {
                return true;
            }
        }

        if(root->right)
        {
            if(getsum1(root,targetSum,sum+root->right->val))
            {
                return true;
            }
        }
        return false;
    }
};